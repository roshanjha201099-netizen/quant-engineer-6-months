#include<bits/stdc++.h>
using namespace std;

using ll = long long;
void solve()
{
    ll n,k,q;
    cin >> n >> k >> q;
    ll cnt=0;
    ll validDays=0;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        if(x<=q) cnt++;
        if(x>q)
        {
            if(cnt>=k)validDays+=(cnt-k+1)*(cnt-k+1+1)/2;
            cnt=0;
        }
    }
    if(cnt>=k)
    {
        validDays+=(cnt-k+1)*(cnt-k+1+1)/2;
    }
    cout << max(0LL,validDays) << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
