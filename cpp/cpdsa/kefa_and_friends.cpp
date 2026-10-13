// Competitive programming template
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 4e18;
const int MOD = 1e9 + 7;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())
void solve() {
    long long n, d;
    cin >> n >> d;

    vector<pair<long long,long long>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(all(arr));

    long long l = 0;
    long long sum = 0;
    long long ans = 0;

    for (long long r = 0; r < n; r++) {

        sum += arr[r].second;

        while (arr[r].first - arr[l].first >= d) {
            sum -= arr[l].second;
            l++;
        }

        ans = max(ans, sum);
    }

    cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
