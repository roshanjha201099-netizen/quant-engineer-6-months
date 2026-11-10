#include <bits/stdc++.h>
using namespace std;

#define int long long
// using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;

vector<int> fact(MAXN), invFact(MAXN);

int modpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;

    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }

    invFact[MAXN-1] = modpow(fact[MAXN-1], MOD-2);

    for (int i = MAXN-2; i >= 0; i--) {
        invFact[i] = invFact[i+1] * (i+1) % MOD;
    }
}
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;

    return fact[n] * invFact[r] % MOD
                  * invFact[n-r] % MOD;
}
void solve() {
    int n,m;
    cin>>n>>m;

    int s = m/2;

    int tot = nCr(m+n-1, n-1);
    int notvalid = nCr(m-s+n-2, n-1);

    int ans = (tot - n * notvalid % MOD + MOD) % MOD;

    cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    precompute();
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
