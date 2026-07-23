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

int nearestToX(vector<int>& pole, int x) {
    int n = pole.size();

    int idx = lower_bound(pole.begin(), pole.end(), x) - pole.begin();

    if (idx == 0) return pole[0];

    if (idx == n) return pole[n - 1];

    int right = pole[idx];      // first element >= x
    int left = pole[idx - 1];   // element < x

    if (x - left <= right - x)
        return left;

    return right;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>city(n),pole(m);
    for(int i=0;i<n;i++)
    {
        cin>>city[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>pole[i];
    }

    //for every city we need to find the diff in distance from it nearest pole and since it is sorted we can use BS for taht 
    int maxi_r=-1e18-200;
    for(int i=0;i<n;i++)
    {
        int city_cordinate=city[i];
        int nearest_pole=nearestToX(pole,city_cordinate);
        maxi_r=max(maxi_r,abs(city_cordinate-nearest_pole));
    }
    cout<<maxi_r<<"\n";
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





 