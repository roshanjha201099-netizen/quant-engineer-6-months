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
void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, int> last;
    last.reserve(2 * n);   // avoids rehashing
    last.max_load_factor(0.7);

    int start = 0;
    int ans = 0;

    for (int end = 0; end < n; end++)
    {
        if (last.count(a[end]))
        {
            start = max(start, last[a[end]] + 1);
        }

        last[a[end]] = end;

        ans = max(ans, end - start + 1);
    }

    cout << ans << '\n';
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





 