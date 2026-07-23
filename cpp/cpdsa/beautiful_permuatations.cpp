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
    if (n == 1) {
            cout << 1 << "\n";
            return;
        }

        if (n == 2 || n == 3) {
            cout << "NO SOLUTION\n";
            return;
        }

      int even=2;
      int odd=1;
      while(even<=n)
      {
        cout<<even<<" ";
        even+=2;
      }
      while(odd<=n)
      {
        cout<<odd<<" ";
        odd+=2;
      }
      cout<<"\n";

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


