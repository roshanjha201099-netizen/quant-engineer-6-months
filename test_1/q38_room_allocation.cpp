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
    cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a[i]={a,b};
    }
    // sort(all(arr));
    for(int i=0;i<n;i++)
    {
        //1,2->1
        //2,4->2
        //4,4-->1(because when i iterated i got something which is less than it)

    }
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





 