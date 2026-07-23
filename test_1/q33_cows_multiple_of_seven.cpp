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
    vector<int>a(n);
    vector<int>pre(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pre[i+1]=(pre[i]+a[i])%7;
    }

    // sort(all(a));
    int maxi=0;
    // int elm=-1;
    //my assumptions are agar koi (b-a)%7=0=>b%7=a%7 second observation is find first elm and last elm and thier distance is maximum we can get.
    for(int elm=0;elm<=6;elm++){
        int first=-9;
        int second=-9;
        for(int i=0;i<=n;i++)
        {
            if(elm==pre[i]){first=i;break;}

        }
        for(int i=n;i>=0;i--)
        {
            if(elm==pre[i]){second=i;break;}

        }
        if(second==first or second<0 or first<0)continue;
        int distance=(second -first);
        maxi=max(distance,maxi);
    }
    cout<<maxi<<"\n";
    //this q ask if the continous block of cows summed such that it is mutiple of 7
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
//i will be strongest .





 
