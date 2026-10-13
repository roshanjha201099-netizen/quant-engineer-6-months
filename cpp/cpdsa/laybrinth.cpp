#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

vector<char> dir = {'U', 'R', 'D', 'L'};

int miniDistance = INT_MAX;
string path = "";

void dfs(string pathused,
         int i, int j,
         vector<string>& v,
         vector<vector<int>>& vis,
         int r, int c,
         int cnter)
{
    vis[i][j] = 1;

    if(v[i][j] == 'B')
    {
        if(cnter < miniDistance)
        {
            miniDistance = cnter;
            path = pathused;
        }

        vis[i][j] = 0;
        return;
    }

    for(int d = 0; d < 4; d++)
    {
        int ni = i + dr[d];
        int nj = j + dc[d];

        if(ni >= 0 && nj >= 0 &&
           ni < r && nj < c &&
           v[ni][nj] != '#' &&
           vis[ni][nj] == 0)
        {
            dfs(pathused + dir[d],
                ni, nj,
                v, vis,
                r, c,
                cnter + 1);
        }
    }

    vis[i][j] = 0;
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

    vector<vector<int>> vis(r, vector<int>(c, 0));

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(v[i][j] == 'A')
            {
                dfs("", i, j, v, vis, r, c, 0);
            }
        }
    }

    if(miniDistance == INT_MAX)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << miniDistance << "\n";
    cout << path << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}