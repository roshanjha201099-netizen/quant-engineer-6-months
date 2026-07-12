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
    // [A,T,T,C,G,G,G,A]
    string s;
    cin>>s;
    int n=s.size();
    int maxi_len=1;
    int curr_len=1;
    char curr=s[0];
    for(int i=1;i<n;i++)
    {
        char ch=s[i];
        if(ch==curr)
        {
            curr_len++;
        }
        else{
            curr=ch;
            maxi_len=max(maxi_len,curr_len);
            curr_len=1;
        }
    }
    maxi_len=max(maxi_len,curr_len);
    cout<<maxi_len<<"\n";
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





 