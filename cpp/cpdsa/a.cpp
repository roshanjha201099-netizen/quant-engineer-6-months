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
    string s;
    cin>>s;
    string ans="";
    int size=s.size();
    for(int i=0;i<size;i++)
    {
        ans+=s[i];
        if(i+1<size){
            ans+="o";
        }
    }
    cout<<ans<<"\n";
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


