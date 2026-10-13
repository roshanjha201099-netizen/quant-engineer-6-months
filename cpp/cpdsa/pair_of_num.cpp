#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 300005;
const int LOG = 20;

ll st[LOG][MAXN];
int lg[MAXN];

ll combine(ll a, ll b) {
    return gcd(a, b);
}

void build(vector<ll>& a) {
    int n = a.size();

    for (int i = 0; i < n; i++) {
        st[0][i] = a[i];
    }

    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            st[k][i] = combine(
                st[k - 1][i],
                st[k - 1][i + (1 << (k - 1))]
            );
        }
    }
}

ll query(int l, int r) {
    int len = r - l + 1;
    int k = lg[len];

    return combine(
        st[k][l],
        st[k][r - (1 << k) + 1]
    );
}

void solve() {

    int n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }

    build(a);

    int maxi = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++) {

        int no = a[i];

        // Find leftmost L
        int lo = 0;
        int hi = i;

        while (lo < hi) {

            int mid = (lo + hi) / 2;

            if (query(mid, i) == no) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        int L = lo;

        // Find rightmost R
        lo = i;
        hi = n - 1;

        while (lo < hi) {

            int mid = (lo + hi + 1) / 2;

            if (query(i, mid) == no) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        int R = lo;

        int len = R - L;

        if (len > maxi) {
            maxi = len;
            ans.clear();
            ans.push_back(L + 1);
        }
        else if (len == maxi) {
            ans.push_back(L + 1);
        }
    }

    cout << ans.size() << " " << maxi << '\n';

    for (int x : ans) {
        cout << x << " ";
    }

    cout << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}