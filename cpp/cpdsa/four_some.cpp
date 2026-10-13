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
  int n,x;
  cin>>n>>x;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  map<int,vector<pair<int,int>>>mp;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
        int val=arr[i]+arr[j];
        if(mp.find(x-val)!=mp.end())
        {
            for(auto it:mp[x-val])
            {
                if(it.first!=i&&it.first!=j&&it.second!=i&&it.second!=j)
                {
                cout<<it.first+1<<' '<<it.second+1<<' '<<i+1<<' '<<j+1<<'\n';
                return;
                }
            }
        }
    }
    for(int j=i+1;j<n;j++)
    {
        int val=arr[i]+arr[j];
        mp[val].push_back({i,j});
    }

  }
  cout<<"IMPOSSIBLE\n";

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


