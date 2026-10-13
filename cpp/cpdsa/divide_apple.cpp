// Competitive programming template
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr ll INF = numeric_limits<ll>::max() / 4;
constexpr int MOD = 1'000'000'007;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template <typename T>
void read(vector<T>& a) {
	for (auto& value : a) cin >> value;
}

void solve() {
    int n;
    cin>>n;
    vector<long long>arr(n);
    for(auto &x:arr)cin>>x;
    long long ts=accumulate(all(arr),0LL);
    long long mini=INF;
    for(int mask=0;mask<(1<<n);mask++){
        long long sum=0;
        for(int i=0;i<n;i++){
            if(mask &(1<<i)){
                sum+=arr[i];
            }
        }
        long long rem=ts-sum;
        mini=min(mini,abs(rem-sum));
    }
    cout<<mini<<"\n";
}


void printSubsets(){
    int n=4;
    vector<int>arr={1,2,3,4};
    int noOfSubsets=(1<<n);
    for(int mask=0;mask<noOfSubsets;mask++){
        cout<<"{ ";
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                cout<<arr[i]<<", ";
            }
        }
        cout<<"}\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_cases = 1;
	// cin >> test_cases;
	while (test_cases--) solve();

	return 0;
}
