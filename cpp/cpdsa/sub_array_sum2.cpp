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
    //dont suggest me okay 
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>pre(n+1,0);
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i]+arr[i];
    }
    map<int,int>mp;
    mp[0]=1;
    int ans=0;
    //pre[i]-pre[j]=k==> pre[i]-k=pre[j]  ye kitni baar aaya utna baar ye possible hoga ki uske beech mein sum k bana sakta haicool hai 
    for(int i=1;i<=n;i++)
    {
        ans+=mp[pre[i]-k];
        mp[pre[i]]++;
    }
    cout<<ans<<"\n";
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


