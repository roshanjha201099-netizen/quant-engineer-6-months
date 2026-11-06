
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

class FenwickTree {
    vector<int> tree;
    int n;

public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void update(int idx, int val) {
        while (idx <= n) {
            tree[idx] = (tree[idx] + val) % MOD;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int sum = 0;

        while (idx > 0) {
            sum = (sum + tree[idx]) % MOD;
            idx -= (idx & -idx);
        }

        return sum;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Precompute powers of 2
    vector<int> pw2(n), inv2pow(n);

    pw2[0] = 1;
    inv2pow[0] = 1;

    int inv2 = (MOD + 1) / 2;

    for (int i = 1; i < n; i++) {
        pw2[i] = (pw2[i - 1] * 2) % MOD;
        inv2pow[i] = (inv2pow[i - 1] * inv2) % MOD;
    }

    // Step 2: Coordinate Compression
    vector<int> vals = arr;

    sort(vals.begin(), vals.end());

    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    // Step 3: Fenwick Tree
    FenwickTree ft(vals.size());

    int ans = 0;
     int firstIdx = lower_bound(
        vals.begin(),
        vals.end(),
        arr[0]
    ) - vals.begin() + 1;

   ft.update(firstIdx, inv2pow[0]);
    // Step 4: Process original array left to right
    for (int j = 1; j < n; j++) {

        // Find compressed index
        int idx = lower_bound(
            vals.begin(),
            vals.end(),
            arr[j]
        ) - vals.begin() + 1;

        // Sum of weights of previous values <= arr[j]
        int ways = ft.query(idx);

        // Add contribution
        ans = (ans + pw2[j - 1] * ways) % MOD;

        // Insert current element's weight
        ft.update(idx, inv2pow[j]);
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}