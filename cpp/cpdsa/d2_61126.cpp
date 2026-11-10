#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    // Largest element first
    vector<int> ans;
    ans.push_back(a[n - 1]);

    // Remaining elements in ascending order
    for (int i = 0; i < n - 1; i++) {
        ans.push_back(a[i]);
    }

    int sum = ans[0], cnt = 1;

    for (int i = 1; i < n; i++) {
        if (ans[i] * i >= sum) cnt++;
        sum += ans[i];
    }

    if (cnt != k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto x : ans) cout << x << " ";
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}