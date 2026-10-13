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
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cnt1=0;
    int cnt10=0;
    int cnt100=0;
    for(int i=0;i<n;i++)
    {
        int no=arr[i]+999;
        int fac=no/1000;
        int rem=fac*1000-arr[i];
        cnt100+=(rem/100);
        int x=rem/100;
        rem=rem-x*100;
        cnt10+=(rem/10);
        int y=rem/10;
        rem=rem-y*10;
        cnt1+=(rem/1);
    }
    cout<<cnt1<<" "<<cnt10<<" "<<cnt100<<"\n";
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


