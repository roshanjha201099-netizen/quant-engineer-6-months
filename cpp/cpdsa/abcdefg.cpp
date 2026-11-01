#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return false;

        if (sz[x] < sz[y]) swap(x, y);

        par[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>edges(m);
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i]={u,v,w};
    }
    sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
        return a[2]>b[2];
    });
    DSU dsu(n);
    int start=0;
    int end=0;
    int mini=1e9;
    for(int i=0;i<m;i++){
        auto it=edges[i];
        if(dsu.unite(it[0],it[1])){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }else{
            if(mini>it[2]){
                mini=min(it[2],mini);
                start=it[0];
                end=it[1];
            }
        }
    }
   vector<int> par(n+1, -1);

function<bool(int,int)> dfs = [&](int u,int p) {
    if(u == end) return true;

    for(int v : graph[u]) {
        if(v == p) continue;

        par[v] = u;

        if(dfs(v,u)) return true;
    }

    return false;
};

dfs(start,-1);

vector<int> path;
int curr = end;

while(curr != start) {
    path.push_back(curr);
    curr = par[curr];
}

path.push_back(start);
reverse(path.begin(),path.end());

cout << mini << " " << path.size() << "\n";

for(auto x : path) cout << x << " ";
cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}