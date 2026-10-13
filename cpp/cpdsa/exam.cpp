#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }
    sort(arr.begin(),arr.end());
    int mini=1e9;
    int limit=min(arr[0].first,arr[0].second);
    for(int i=1;i<arr.size();i++){
        auto it=arr[i];
        int b=it.second;
        if(b>=limit){
            limit=b;
        }else{
            limit=it.first;
        }

        if(i==arr.size()-1){
            mini=limit;
        }
    }
    cout<<limit<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}