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
    int n,q;
    cin>>n>>q;
    vector<vector<int>>pre(n+1,vector<int>(n+1,0));
    vector<vector<char>>c(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(c[i][j]=='*')
            {
                pre[i+1][j+1]=-pre[i][j]+(pre[i][j+1]+pre[i+1][j])+1;
            }else{
                
                pre[i+1][j+1]=-pre[i][j]+(pre[i][j+1]+pre[i+1][j]);
            }
        }
    }
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<pre[c][d]-pre[a-1][d]-pre[c][b-1]+pre[a-1][b-1]<<"\n";
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


