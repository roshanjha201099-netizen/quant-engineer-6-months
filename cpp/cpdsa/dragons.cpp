// Compact competitive-programming template
#include <bits/stdc++.h>
using namespace std;

namespace cp {
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int INF = 1'000'000'000;
constexpr i64 LINF = 4'000'000'000'000'000'000LL;

template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

template<class T>
istream& operator>>(istream& in, vector<T>& a) {
	for (auto& x : a) in >> x;
	return in;
}

template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {
	for (size_t i = 0; i < a.size(); ++i)
		out << (i ? " " : "") << a[i];
	return out;
}

template<class T>
void chmin(T& a, const T& b) { if (b < a) a = b; }

template<class T>
void chmax(T& a, const T& b) { if (a < b) a = b; }

struct DSU {
	vector<int> p, size;
	explicit DSU(int n = 0) { reset(n); }
	void reset(int n) { p.resize(n); size.assign(n, 1); iota(p.begin(), p.end(), 0); }
	int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
	bool unite(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return false;
		if (size[a] < size[b]) swap(a, b);
		p[b] = a; size[a] += size[b];
		return true;
	}
};
} // namespace cp

using namespace cp;

void solve() {
    i64 s,n;
    cin>>s>>n;
    vector<pair<i64,i64>>arr(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }
    sort(arr.begin(),arr.end(),[&](pair<i64,i64>&a,pair<i64,i64>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    });
    for(int i=0;i<n;i++){
        if(arr[i].first<s){
            s+=arr[i].second;
        }else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tests = 1;
	// cin >> tests; // Uncomment for multiple test cases.
	while (tests--) solve();
	return 0;
}
