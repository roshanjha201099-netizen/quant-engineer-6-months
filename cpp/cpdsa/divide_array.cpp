#include <bits/stdc++.h>
using namespace std;

bool valid(long long mx, int k, vector<int>& arr) {
    int cnt = 1;
    long long sum = 0;

    for (int x : arr) {
        if (sum + x > mx) {
            cnt++;
            sum = x;
        } else {
            sum += x;
        }
    }

    return cnt <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    long long lo = *max_element(arr.begin(), arr.end());
    long long hi = accumulate(arr.begin(), arr.end(), 0LL);

    long long ans = hi;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        if (valid(mid, k, arr)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}