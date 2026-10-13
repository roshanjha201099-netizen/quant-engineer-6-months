#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, -1);
    vector<int> path;

    function<bool(int, int)> dfs = [&](int no, int parent) {
        vis[no] = 1;

        for (int x : edge[no]) {
            if (x == parent) continue;

            if (vis[x]) {
                // Cycle found: x is an ancestor of no
                path.push_back(x);

                int curr = no;
                while (curr != x) {
                    path.push_back(curr);
                    curr = par[curr];
                }

                path.push_back(x);
                return true;
            }

            par[x] = no;

            if (dfs(x, no)) return true;
        }

        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                cout << path.size() << "\n";

                for (int x : path) {
                    cout << x << " ";
                }

                cout << "\n";
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}