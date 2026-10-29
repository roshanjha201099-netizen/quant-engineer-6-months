#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF=1e18+200;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>graph(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    vector<int>dist(n+1,INF);
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [cost,u]=pq.top();
        pq.pop();
        if(cost!=dist[u])continue;
        for(auto [v,w]:graph[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=w+dist[u];
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}