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

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int moving_sum=0;
    int maximums_sum=(-1e9)-200;
    for(int i=0;i<n;i++)
    {
        moving_sum+=arr[i];
        maximums_sum=max(maximums_sum,moving_sum);
        if(moving_sum<0)
        {
            moving_sum=0;
        }
    }
    cout<<maximums_sum<<"\n";
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





 