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
    int n,t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int start=0;
    int sum=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<=t)
        {
            maxi=max(i-start+1,maxi);
            continue;
        }
        while(i>=start and sum>t)
        {
            sum-=arr[start];
            start++;
        }
    }
    cout<<maxi<<"\n";
}
// 3 1 2 1

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





 