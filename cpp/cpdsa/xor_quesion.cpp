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


void solve(int n,int q)
{
    vector<int>arr(n);
    vector<int>pre(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        pre[i+1]=(pre[i]^arr[i]);
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<(pre[r]^pre[l-1])<<"\n";
    }
}

 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--) {
        int n,q;
        cin>>n>>q;
        solve(n,q);
    }
    return 0;
}
//i will be strongest .


