
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

void sol(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> graph(n+1);

    for(int i=0; i<m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }

    vector<vector<ll>> dp(n+1, vector<ll>(2, INF));

    priority_queue<
        tuple<ll,int,int>,
        vector<tuple<ll,int,int>>,
        greater<tuple<ll,int,int>>
    > pq;

    dp[1][0] = 0;
    pq.push({0,1,0});

    while(!pq.empty()){
        auto [cost,u,state] = pq.top();
        pq.pop();

        if(cost != dp[u][state]) continue;

        for(auto [v,w] : graph[u]){

            
            if(cost+w < dp[v][state]){
                dp[v][state] = cost+w;
                pq.push({dp[v][state],v,state});
            }

            if(state == 0){
                if(cost+w/2 < dp[v][1]){
                    dp[v][1] = cost+w/2;
                    pq.push({dp[v][1],v,1});
                }
            }
        }
    }

    cout << dp[n][1] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sol();
    return 0;
}
