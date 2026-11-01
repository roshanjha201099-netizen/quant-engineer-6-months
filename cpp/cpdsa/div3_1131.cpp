#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve_e() {
    int n;
    cin >> n;

    vector<int> arr(n);

    int mini = LLONG_MAX;
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        mini = min(mini, abs(arr[i]));

        if (arr[i] < 0) cnt++;

        sum += abs(arr[i]);
    }

    if (n == 1) {
        cout << arr[0] << '\n';
        return;
    }

    if (cnt % 2 == 1) {
        sum -= 2 * mini;
    }

    cout << sum << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve_e();

    return 0;
}