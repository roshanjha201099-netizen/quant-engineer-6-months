#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
    // Implement the solution logic here

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>grp(n+1,0);
    vector<int>vis(n+1,0);
    function<bool(int, int)> dfs = [&](int no, int par) {
    vis[no] = 1;

    for (auto x : adj[no]) {
        if (x == par) continue;

        if (vis[x]) {
            if (grp[x] == grp[no]) return true;
            continue;
        }

        grp[x] = 3 - grp[no];

        if (dfs(x, no)) return true;
    }

    return false;
};
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            grp[i]=1;
            if(dfs(i,-1)){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
    // cout<<"YES\n";
    for(int i=1;i<=n;i++){
        cout<<grp[i]<<" ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    // Write your code here

    return 0;
}
