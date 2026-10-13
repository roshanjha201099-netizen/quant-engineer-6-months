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


bool valid(int mid,int t,int n,vector<int>&arr)
{
   int tot=0;
   for(int i=0;i<n;i++)
   {
    tot+=(mid/arr[i]);
   }
   return tot>=t;
}

void solve()
{

    int n,t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr[i]=val;
    }
    sort(all(arr));
    int ans=0;
    int lo=arr[0];
    int hi=arr[0] * t;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(valid(mid,t,n,arr)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }    
    cout<<ans<<"\n";
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


