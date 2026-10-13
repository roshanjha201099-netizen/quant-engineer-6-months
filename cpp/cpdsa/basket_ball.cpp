#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = (1LL << 62);
const int MOD = 1'000'000'007;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    ll n,d;
    cin>>n>>d;
    vector<int>a(n);
    for(auto &v:a)cin>>v;
    sort(all(a));
    int i=-1;
    int j=n-1;
    int cnt=0;
    while(i<j){
        int val=a[j];
        int reqm=d/val;
        int sum=val+val*reqm;
        i=i+reqm;
        if(i<j and sum>d){
            cnt++;
            j--;
        }
    }
    cout<<cnt<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}