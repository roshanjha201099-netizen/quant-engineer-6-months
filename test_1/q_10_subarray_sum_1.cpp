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
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int start=0;
    int moving_sum=0;
    int counter=0;
    for(int i=0;i<n;i++)
    {
        moving_sum+=arr[i];
       
        while(moving_sum>x)
        {
            moving_sum-=arr[start];
            start++;
        }
         if(moving_sum==x)
        {
            counter++;
        }
    }
    cout<<counter<<"\n";
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





 