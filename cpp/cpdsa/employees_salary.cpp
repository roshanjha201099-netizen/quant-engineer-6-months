
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

class FenwickTree {
    vector<int> tree;
    int n;

public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void update(int idx, int del) {
        while (idx <= n) {
            tree[idx] += del;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> salary(n);
    for (int i = 0; i < n; i++) {
        cin >> salary[i];
    }

    // Store all queries first
    vector<tuple<char, int, int>> queries;
    vector<int> vals = salary;

    for (int i = 0; i < q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        queries.push_back({type, a, b});

        // Include future salary updates
        if (type == '!') {
            vals.push_back(b);
        }
    }

    // Coordinate compression
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FenwickTree ft(vals.size());

    // Insert initial salaries
    for (int x : salary) {
        int idx = lower_bound(all(vals), x) - vals.begin() + 1;
        ft.update(idx, 1);
    }

    // Process queries
    for (auto [type, a, b] : queries) {

        if (type == '!') {
            int k = a;
            int x = b;

            // Remove old salary
            int oldIdx = lower_bound(all(vals), salary[k - 1])
                         - vals.begin() + 1;

            ft.update(oldIdx, -1);

            // Update salary
            salary[k - 1] = x;

            // Insert new salary
            int newIdx = lower_bound(all(vals), x)
                         - vals.begin() + 1;

            ft.update(newIdx, 1);
        }

        else {
            int l = a;
            int r = b;

            // Number of compressed values <= r
            int rightIdx = upper_bound(all(vals), r)
                           - vals.begin();

            // Number of compressed values < l
            int leftIdx = lower_bound(all(vals), l)
                          - vals.begin();

            cout << ft.query(rightIdx) - ft.query(leftIdx)
                 << '\n';
        }
    }
}

int main() {
    fastio;
    solve();
    return 0;
}
