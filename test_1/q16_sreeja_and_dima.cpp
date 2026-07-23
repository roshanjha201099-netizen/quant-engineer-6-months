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
    int left=0;
    int right=n-1;
    //left right mein se koi bhi ek choose kar sakta hai and usko move kar dega jaha se lia and add them 
    int sreeja=0;
    int dima=0;
    int chances=0;
    while(left<=right)
    {
        
        if(arr[left]>arr[right])
        {
            if(chances%2==0)
            {
                sreeja+=arr[left];
            }else{
                dima+=arr[left];
            }
            left++;
        }else{
            if(chances%2==0)
            {
                sreeja+=arr[right];
            }else{
                dima+=arr[right];
            }
            right--;
        }
        chances++;
    }
    cout<<sreeja<<" "<<dima<<"\n";
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





 