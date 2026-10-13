
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int>odd,even;
    int ans=0;
    for(int i=0;i<n-4;i++){
        int x=i;
        int x_2=i+2;
        int x_4=i+4;
        int cal=a[x]+a[x_2]-a[x_4];
        if(i%2==0){
            even[cal]++;
        }else{
            odd[cal]++;
        }

        if(odd[cal] and even[cal]){
            int way=0;
            if(i%2==0){
                way=odd[cal];
                way+=//and also even which are at -4 below
            }else{
                way=even[cal];
                way+=//and also odd which are at -4 below
            }
            ans+=way*(way-1)/2;
        }

    }
    cout<<ans<<"\n";
    //see the number of ways will be if i is odd than all its previous even and all the (odd)which is at -4 position will be valid for it so allthose C 2 will be answer.

}


int main() {
    FAST_IO;

    int tc = 1;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}