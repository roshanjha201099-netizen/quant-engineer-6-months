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
  int n,a,b;
  cin>>n>>a>>b;
  vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
  vector<int>pref(n+1,0);
  for(int i=0;i<n;i++)
  {
    pref[i+1]=pref[i]+arr[i];
  }
  deque<int>dq;
  int maxi=-(1e18);
  for(int i=a;i<=n;i++)
  {
    int idx=i-a;
    while(!dq.empty() and pref[dq.back()]>=pref[idx])
    {
        dq.pop_back();
    }
    dq.push_back(idx);
    while(!dq.empty() and dq.front()<i-b)
    {
        dq.pop_front();
    }
    maxi=max(maxi,pref[i]-pref[dq.front()]);
  }
    cout<<maxi<<"\n";

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


