#include<bits/stdc++.h> 
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
    vector<int> a(n);
    int sum=0;
    int prev=-99;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0)
        {
            prev=a[i];
            continue;
        }
        if(prev>a[i])
        {
            sum+=(prev-a[i]);
        }else{
            prev=a[i];
        }
    }
    cout<<sum<<"\n";
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





 