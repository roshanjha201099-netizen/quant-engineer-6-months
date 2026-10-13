#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    while(m--){
        //do bs on map 
        //if foudn print the value other wise -1
        int a;
        cin>>a;
       auto it = mp.upper_bound(a);

        if (it != mp.begin()) {
            --it;

            cout << it->first << "\n";

            mp[it->first]--;

            if (mp[it->first] == 0) {
                mp.erase(it->first);
            }
        }
        else {
            cout << -1 << "\n";
        }

    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}