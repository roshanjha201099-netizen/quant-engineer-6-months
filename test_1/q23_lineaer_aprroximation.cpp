#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) (a).begin(), (a).end()

int getMedian(vector<int> &v)
{
    sort(all(v));
    return v[v.size() / 2];
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b[i] = arr[i] - (i + 1);
    }

    int median = getMedian(b);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs((arr[i] - (i + 1)) - median);
    }

    cout << ans << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}