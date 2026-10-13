#include <bits/stdc++.h>
using namespace std;

#define sanjonaily ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;
const ll INF = 4e18;

bool check(map<int, int>& mp, int sp) {

    // first ending time > sp
    auto it = mp.upper_bound(sp);

    // no ending time <= sp
    if (it == mp.begin())
        return false;

    // largest ending time <= sp
    --it;

    int t = it->first;

    // one member becomes occupied
    it->second--;

    // no member is free at this time anymore
    if (it->second == 0)
        mp.erase(t);

    return true;
}

void solve() {

    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(all(arr), [](const pair<int,int>& a,
                      const pair<int,int>& b) {

        if (a.second == b.second)
            return a.first < b.first;

        return a.second < b.second;
    });

    // All k members are initially free at time 0
    map<int,int> mp;
    mp[0] = k;

    int cnt = 0;

    for (auto [sp, ep] : arr) {

        if (check(mp, sp)) {
            cnt++;

            // this member becomes free at ep
            mp[ep]++;
        }
    }

    cout << cnt << '\n';
}

int main() {

    sanjonaily;

    solve();

    return 0;
}