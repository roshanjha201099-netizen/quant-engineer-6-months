#include <bits/stdc++.h>
using namespace std;
 
 
// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define debug(...) 8
// #endif
 
 
const int M = 1e9 + 7;
#define int long long
#define all(a) (a).begin(), (a).end()
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int,int> mp;
    int start = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(mp.find(arr[i]) != mp.end())
        {
            start = max(start, mp[arr[i]] + 1);
        }
        mp[arr[i]] = i;
        ans += (i - start + 1);
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


