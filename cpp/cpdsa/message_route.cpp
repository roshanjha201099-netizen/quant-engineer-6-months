#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define each(x, it) for (auto &it : x)


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int>q;
    vector<int>dist(n+1,-1);
    vector<int>parent(n+1,-1);
    q.push(1);
    dist[1]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==n){break;}
        for(auto &v:adj[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
    if(dist[n]==-1){cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int>path;
        int tar=n;
        while(tar!=-1){
            path.pb(tar);
            tar=parent[tar];
        }
        reverse(all(path));
        cout<<sz(path)<<"\n";
        for(auto &x:path)cout<<x<<" ";
    }
}

int main() {
    fastio;

    int t=1;
    // cin >> t;
    while (t--) {
        // Solve each test case here
        solve();
    }

    return 0;
}
