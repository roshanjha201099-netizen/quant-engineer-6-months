#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(2,0));
    vector<pair<int,int>>events;
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
        events.push_back({a[i][0],1});
        events.push_back({a[i][1],-1});
    }
    sort(events.begin(),events.end());
    int cnt=0;
    int maxi=0;
    for(int i=0;i<events.size();i++)
    {
        cnt+=(events[i].second);
        maxi=max(cnt,maxi);
    }
    cout<<maxi<<"\n";

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
}