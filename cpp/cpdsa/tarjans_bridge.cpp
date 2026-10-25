#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCases = 1;
	// Uncomment the next line for multiple test cases.
	// cin >> testCases;

	while (testCases--) {
		solve();
	}

	return 0;
}
