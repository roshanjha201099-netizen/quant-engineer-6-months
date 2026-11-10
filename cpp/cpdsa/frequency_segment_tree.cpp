
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int n) : n(n), tree(4*n, 0) {}

    void update(int idx, int start, int end, int pos, int del) {
        if (start == end) {
            tree[idx] += del;
            return;
        }

        int mid = start + (end-start)/2;

        if (pos <= mid) {
            update(2*idx, start, mid, pos, del);
        } else {
            update(2*idx+1, mid+1, end, pos, del);
        }

        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    int query(int idx, int start, int end, int l, int r) {
        if (l > end || r < start) return 0;

        if (start >= l && end <= r) {
            return tree[idx];
        }

        int mid = start + (end-start)/2;

        return query(2*idx, start, mid, l, r)
             + query(2*idx+1, mid+1, end, l, r);
    }
};

void salary() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> vals = arr;
    vector<tuple<char,int,int>> queries;

    for (int i = 0; i < q; i++) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;

        queries.push_back({ch, a, b});

        if (ch == '!') {
            vals.push_back(b);
        } else {
            vals.push_back(a);
            vals.push_back(b);
        }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    SegmentTree st(vals.size());

    // Insert initial salaries
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vals.begin(), vals.end(), arr[i])
                  - vals.begin();

        st.update(1, 0, vals.size()-1, idx, 1);
    }

    for (auto [type, a, b] : queries) {

        if (type == '!') {
            int pos = a - 1;

            // Remove old salary
            int oldIdx = lower_bound(vals.begin(), vals.end(), arr[pos])
                         - vals.begin();

            st.update(1, 0, vals.size()-1, oldIdx, -1);

            // Update actual array
            arr[pos] = b;

            // Insert new salary
            int newIdx = lower_bound(vals.begin(), vals.end(), b)
                         - vals.begin();

            st.update(1, 0, vals.size()-1, newIdx, 1);
        }
        else {
            int l = lower_bound(vals.begin(), vals.end(), a)
                    - vals.begin();

            int r = upper_bound(vals.begin(), vals.end(), b)
                    - vals.begin() - 1;

            int ans = st.query(1, 0, vals.size()-1, l, r);

            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    salary();

    return 0;
}
