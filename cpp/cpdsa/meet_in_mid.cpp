#include <bits/stdc++.h>
using namespace std;

void generate(int idx, int end,
              long long sum,
              vector<long long>& arr,
              vector<long long>& sums){

    if(idx == end){
        sums.push_back(sum);
        return;
    }

    // current element nahi liya
    generate(idx + 1, end, sum, arr, sums);

    // current element liya
    generate(idx + 1, end, sum + arr[idx], arr, sums);
}

void solve(){

    int n;
    long long x;

    cin >> n >> x;

    vector<long long> arr(n);

    for(auto &a : arr)
        cin >> a;

    int half = n / 2;

    vector<long long> left, right;

    // First half ke saare subset sums
    generate(0, half, 0, arr, left);

    // Second half ke saare subset sums
    generate(half, n, 0, arr, right);

    // Binary search ke liye sort
    sort(left.begin(), left.end());

    long long ans = 0;

    // Har right subset ke liye required left sum
    for(long long sum : right){

        long long need = x - sum;

        // left mein need kitni baar aaya?,l
        auto lo = lower_bound(left.begin(), left.end(), need);
        auto hi = upper_bound(left.begin(), left.end(), need);

        ans += (hi - lo);
    }

    cout << ans << '\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}