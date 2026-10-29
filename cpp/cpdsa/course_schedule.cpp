
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    // 0 = not visited, 1 = currently in DFS path, 2 = processed
    vector<int> vis(n + 1, 0);
    vector<int> order;

    function<bool(int)> dfs = [&](int u) {
        vis[u] = 1;

        for (int v : graph[u]) {
            if (vis[v] == 1) {
                return true; // Cycle detected
            }

            if (vis[v] == 0 && dfs(v)) {
                return true;
            }
        }

        vis[u] = 2;
        order.push_back(u);
        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && dfs(i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    reverse(order.begin(), order.end());

    for (int u : order) {
        cout << u << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
