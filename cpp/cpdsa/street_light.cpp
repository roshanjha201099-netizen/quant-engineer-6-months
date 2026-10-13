// Competitive programming template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr int INF = 1e9;
constexpr ll LINF = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
 int x, n;
cin >> x >> n;

map<int, int> mp;

mp[0] = 1;
mp[x] = 1;

map<int, int> mp1;

mp1[x] = 1;

while(n--) {

    int val;
    cin >> val;

    auto it1 = mp.lower_bound(val);

    int lb = 0;

    if(it1 != mp.begin()) {
        --it1;
        lb = it1->first;
    }

    int ub = x;

    auto it2 = mp.upper_bound(val);

    if(it2 != mp.end()) {
        ub = it2->first;
    }

    int oldLen = ub - lb;

    mp1[oldLen]--;

    if(mp1[oldLen] == 0)
        mp1.erase(oldLen);

    mp1[val - lb]++;
    mp1[ub - val]++;

    mp[val] = 1;

    cout << mp1.rbegin()->first << " ";
}

cout << '\n';


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_cases = 1;
	// cin >> test_cases;
	while (test_cases--) {
		solve();
	}

	return 0;
}
