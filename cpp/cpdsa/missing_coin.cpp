#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr ll INF = (1LL << 62);
constexpr int MOD = 1'000'000'007;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())

template <typename T>
void read(vector<T>& a) {
    for (auto& x : a) cin >> x;
}

void solve() {
    long long n;
    cin>>n;
    vector<long long>arr(n);
    read(arr);
    sort(all(arr));
    long long ol=0;
    long long olr=0;
    for(long long i=0;i<n;i++){
        long long X=arr[i];
        long long nl=ol+X;
        long long nr=olr+X;
        if(nl>olr+1){
            cout<<olr+1<<"\n";
            return;
        }
        olr=nr;
    }
    cout<<olr+1<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}