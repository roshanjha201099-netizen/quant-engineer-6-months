
#include <bits/stdc++.h>
using namespace std;

#define int long long

class PersistentSegmentTree {
    class Node {
    public:
        int left, right, sum;

        Node() {
            left = right = sum = 0;
        }
    };

    vector<Node> tree;
    int n;

    int update(int prev, int start, int end, int pos) {
        int curr = tree.size();
        tree.push_back(tree[prev]);

        if (start == end) {
            tree[curr].sum++;
            return curr;
        }

        int mid = start + (end - start) / 2;

        if (pos <= mid) {
            tree[curr].left =
                update(tree[prev].left, start, mid, pos);
        }
        else {
            tree[curr].right =
                update(tree[prev].right, mid + 1, end, pos);
        }

        tree[curr].sum =
            tree[tree[curr].left].sum +
            tree[tree[curr].right].sum;

        return curr;
    }

    int kthLargest(int u, int v, int start, int end, int k) {
        if (start == end) {
            return start;
        }

        int mid = start + (end - start) / 2;

        int rightCount =
            tree[tree[v].right].sum -
            tree[tree[u].right].sum;

        if (k <= rightCount) {
            return kthLargest(
                tree[u].right,
                tree[v].right,
                mid + 1,
                end,
                k
            );
        }

        return kthLargest(
            tree[u].left,
            tree[v].left,
            start,
            mid,
            k - rightCount
        );
    }

public:
    vector<int> root;

    PersistentSegmentTree(int n) : n(n) {
        tree.push_back(Node()); // Null node
        root.push_back(0);      // Empty version
    }

    void insert(int pos) {
        root.push_back(
            update(root.back(), 0, n - 1, pos)
        );
    }

    int query(int l, int r, int k) {
        return kthLargest(
            root[l - 1],
            root[r],
            0,
            n - 1,
            k
        );
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // Coordinate compression
    vector<int> values = a;

    sort(values.begin(), values.end());
    values.erase(
        unique(values.begin(), values.end()),
        values.end()
    );

    int m = values.size();

    PersistentSegmentTree pst(m);

    // Build prefix versions
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(
            values.begin(), values.end(), a[i]
        ) - values.begin();

        pst.insert(pos);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        int compressedIndex = pst.query(l, r, k);

        cout << values[compressedIndex] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
