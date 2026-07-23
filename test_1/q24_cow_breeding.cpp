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

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>p1(n+1,0),p2(n+1,0),p3(n+1,0);
    for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            p1[i+1] = p1[i];
            p2[i+1] = p2[i];
            p3[i+1] = p3[i];

            if(x == 1)
                p1[i+1]++;
            else if(x == 2)
                p2[i+1]++;
            else
                p3[i+1]++;
        }
   
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int b1=p1[b]-p1[a-1];
        int b2=p2[b]-p2[a-1];
        int b3=p3[b]-p3[a-1];
        cout<<b1<<" "<<b2<<" "<<b3<<"\n";
    }
    
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
//i will be strongest .





 
