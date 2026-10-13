
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

bool check(int r, int c, int n, int m, vector<vector<char>>& grid) {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    queue<pair<int,int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int,int>>> parent(
        n, vector<pair<int,int>>(m, {-1, -1})
    );

    q.push({r, c});
    vis[r][c] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dr[i];
            int ny = y + dc[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (grid[nx][ny] != grid[r][c])
                continue;

            if (!vis[nx][ny]) {
                vis[nx][ny] = 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
            else if (parent[x][y] != make_pair(nx, ny)) {
                return true;
            }
        }
    }

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(i, j, n, m, grid)) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int main() {
    fastio;
    solve();
    return 0;
}
