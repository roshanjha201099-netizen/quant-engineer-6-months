#include <bits/stdc++.h>
using namespace std;
 
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 8
#endif
 
 
const int M = 1e9 + 7;
#define int long long
#define all(a) (a).begin(), (a).end()
using pii = pair<int, int>;
void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> pre(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pre[i + 1] = pre[i] + arr[i];
    }

    for (int i = 0; i <= n; i++) {
        pre[i] %= n;

        if (pre[i] < 0) {
            pre[i] += n;
        }
    }

    sort(all(pre));

    int ans = 0;

    for (int i = 0; i <= n;) {
        int j = i;

        while (j <= n && pre[j] == pre[i]) {
            j++;
        }

        int cnt = j - i;

        ans += cnt * (cnt - 1) / 2;

        i = j;
    }

    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
//i will be strongest .





 