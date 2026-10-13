#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    bool isCycle;

    function<void(int)> dfs = [&](int node) {
        
        visited[node] = true;

        // In a cycle, every vertex must have degree 2
        //to have full coponenet as cycle there must exist the degree of each node as =2
        if (adj[node].size() != 2) {
            isCycle = false;
        }

        for (auto x : adj[node]) {
            if (!visited[x]) {
                dfs(x);
            }
        }
    };

    int cnt = 0;

    for (int i = 1; i <= n; i++) {

        if (!visited[i]) {

            // Assume this component is a cycle
            isCycle = true;

            // Traverse this complete component
            dfs(i);

            if (isCycle) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}

int main() {
    fastio;

    solve();

    return 0;
}