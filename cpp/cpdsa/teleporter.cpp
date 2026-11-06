
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    // Degree check
    int odd = 0;

    for (int i = 1; i <= n; i++) {
        if (graph[i].size() % 2 != 0) {
            odd++;
        }
    }

    if (odd != 0 && odd != 2) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> used(m, 0);
    vector<int> ans;

    function<void(int)> dfs = [&](int u) {
        while (!graph[u].empty()) {
            auto [v, id] = graph[u].back();
            graph[u].pop_back();

            if (used[id]) continue;

            used[id] = 1;
            dfs(v);
        }

        ans.push_back(u);
    };

    dfs(1);

    reverse(ans.begin(), ans.end());

    // Check whether all edges were used
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
