#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }

    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, -1);

    function<bool(int)> dfs = [&](int node) {
        vis[node] = 1;

        for (auto x : edge[node]) {

            if (vis[x] == 1) {
                vector<int> path;

                int curr = node;
                path.push_back(x);

                while (curr != x) {
                    path.push_back(curr);
                    curr = par[curr];
                }

                path.push_back(x);
                reverse(path.begin(), path.end());

                cout << path.size() << "\n";

                for (auto v : path) {
                    cout << v << " ";
                }
                cout << "\n";

                return true;
            }

            if (vis[x] == 0) {
                par[x] = node;

                if (dfs(x)) {
                    return true;
                }
            }
        }

        vis[node] = 2;
        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (dfs(i)) {
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}