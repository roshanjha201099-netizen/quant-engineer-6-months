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

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>arr(n,{0,0});
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr[i]={val,i};
    }
    sort(all(arr));
    int ans=0;
    vector<int>divider;
    for(int i=n-1;i>=n-k;i--)
    {
        ans+=arr[i].first;
        divider.push_back(arr[i].second);
    }
    sort(all(divider));
    cout<<ans<<'\n';
    int start=0;
    for(int i=0;i<divider.size()-1;i++)
    {
        cout<<divider[i]-start+1<<' ';
        start=divider[i]+1;
    }
    cout<<n-start<<'\n';
    
}

 
signed main() {
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


