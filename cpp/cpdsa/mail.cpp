
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);
    vector<int> usedid(m, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }


    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    vector<int> ans;

    function<void(int)> dfs = [&](int u) {
        while (!adj[u].empty()) {
            auto [v, id] = adj[u].back();
            adj[u].pop_back();

            if (usedid[id]) continue;

            usedid[id] = 1;
            dfs(v);
        }

        ans.push_back(u);
    };

    dfs(1);

    reverse(ans.begin(), ans.end());

    if (ans.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
