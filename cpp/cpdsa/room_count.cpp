#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

void dfs(int i, int j, vector<string>& v,
         vector<vector<int>>& vis, int r, int c)
{
    vis[i][j] = 1;

    for(int x = 0; x < 4; x++)
    {
        int ni = i + dr[x];
        int nj = j + dc[x];

        if(ni >= 0 && nj >= 0 && ni < r && nj < c &&
           v[ni][nj] == '.' && vis[ni][nj] == 0)
        {
            dfs(ni, nj, v, vis, r, c);
        }
    }
}

void solve()
{
    int r, c;
    cin >> r >> c;

    vector<string> v(r);

    for(int i = 0; i < r; i++)
    {
        cin >> v[i];
    }

    int cnt = 0;

    vector<vector<int>> vis(r, vector<int>(c, 0));

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(v[i][j] == '.' && vis[i][j] == 0)
            {
                cnt++;

                dfs(i, j, v, vis, r, c);
            }
        }
    }

    cout << cnt << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    // cin >> t;

    while(t--)
    {
        solve();
    }
}