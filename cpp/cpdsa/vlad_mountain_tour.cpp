#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
	vector<int> parent, size;

public:
	DSU(int n) : parent(n+1), size(n+1, 1) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int x) {
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}

	bool unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (size[a] < size[b]) swap(a, b);
		parent[b] = a;
		size[a] += size[b];
		return true;
	}
    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>ht(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> ht[i];
    }
    vector<vector<int>>graph(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>order(n);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return ht[a] < ht[b];
    });
    int q;
    cin >> q;
    vector<vector<int>>queries(n+1);
    for(int i = 0; i < q; i++) {
        int u, v,e;
        cin >> u >> v >> e;
        int threshold = ht[u] + e;
        queries[i]={threshold, u, v, i};
    }
    sort(queries.begin(), queries.end());
    vector<bool>ans(q);
    DSU dsu(n);
    int ptr=0;
    vector<int>active(n+1, 0);
    for(auto &[threshold, u, v, idx]: queries) {
        while(ptr < n && ht[order[ptr]] <= threshold) {
            int node = order[ptr];
            active[node] = 1;
            for(int neighbor: graph[node]) {
                if(active[neighbor]) {
                    dsu.unite(node, neighbor);
                }
            }
            ptr++;
        }
        ans[idx] =active[v] and dsu.isConnected(u, v);
    }
    for(int i = 0; i < q; i++) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	return 0;
}
