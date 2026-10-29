
#include <bits/stdc++.h>
using namespace std;

#define int long long

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

    vector<array<int, 4>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][3] = i;
    }

    sort(edges.begin(), edges.end(),
         [](const auto& a, const auto& b) {
             return a[2] < b[2];
         });

    DSU dsu(n);

    // 0 = none, 1 = any, 2 = at least one
    vector<int> ans(m, 0);

    // Original DSU root -> temporary graph vertex ID
    vector<int> tempId(n + 1, -1);

    int i = 0;

    while (i < m) {
        int j = i;

        while (j < m && edges[j][2] == edges[i][2]) {
            j++;
        }

        vector<vector<pair<int, int>>> adj;
        vector<int> usedRoots;

        auto getId = [&](int root) -> int {
            if (tempId[root] != -1) {
                return tempId[root];
            }

            int newId = (int)adj.size();
            tempId[root] = newId;
            usedRoots.push_back(root);
            adj.push_back({});

            return newId;
        };

        // Build temporary graph before merging this weight group.
        for (int k = i; k < j; k++) {
            int u = edges[k][0];
            int v = edges[k][1];
            int eid = edges[k][3];

            int ru = dsu.find(u);
            int rv = dsu.find(v);

            if (ru == rv) continue;

            int a = getId(ru);
            int b = getId(rv);

            adj[a].push_back({b, eid});
            adj[b].push_back({a, eid});

            ans[eid] = 2;
        }

        int V = adj.size();
        vector<int> tin(V, 0), low(V, 0);
        int timer = 0;

        auto dfs = [&](auto&& self, int u, int parentEdge) -> void {
            tin[u] = low[u] = ++timer;

            for (auto [v, eid] : adj[u]) {
                if (eid == parentEdge) continue;

                if (tin[v]) {
                    low[u] = min(low[u], tin[v]);
                } else {
                    self(self, v, eid);

                    low[u] = min(low[u], low[v]);

                    if (low[v] > tin[u]) {
                        ans[eid] = 1;
                    }
                }
            }
        };

        for (int u = 0; u < V; u++) {
            if (!tin[u]) {
                dfs(dfs, u, -1);
            }
        }

        // Only now merge the current weight group.
        for (int k = i; k < j; k++) {
            dsu.unite(edges[k][0], edges[k][1]);
        }

        // Make temporary IDs reusable for the next group.
        for (int root : usedRoots) {
            tempId[root] = -1;
        }

        i = j;
    }

    for (int eid = 0; eid < m; eid++) {
        if (ans[eid] == 1) {
            cout << "any\n";
        } else if (ans[eid] == 2) {
            cout << "at least one\n";
        } else {
            cout << "none\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
