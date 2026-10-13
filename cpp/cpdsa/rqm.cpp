#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200005;
const int LOG = 22;

ll st[LOG][MAXN];
ll lg[MAXN];

ll combine(ll a, ll b)
{
    return min(a, b);
}

void build(vector<ll>& a)
{
    int n = a.size();


    for(int i = 0; i < n; i++)
    {
        st[0][i] = a[i];
    }

  
    for(int k = 1; (1 << k) <= n; k++)
    {
        for(int i = 0; i + (1 << k) <= n; i++)
        {
            st[k][i] = combine(
                st[k - 1][i],
                st[k - 1][i + (1 << (k - 1))]
            );
        }
    }
}

ll query(int l, int r)
{
    int len = r - l + 1;

    int k = lg[len];

    return combine(
        st[k][l],
        st[k][r - (1 << k) + 1]
    );
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // log table
    for(int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    build(a);

    while(q--)
    {
        int x, y;
        cin >> x >> y;

        // CSES uses 1-indexing
        x--;
        y--;

        cout << query(x, y) << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}