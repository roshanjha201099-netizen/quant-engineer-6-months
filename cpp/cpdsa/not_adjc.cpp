#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

void solve() {
    int n;
    cin>>n;
    if(n==1){
        cout<<"1\n";
        return ;
    }else if(n==2){
        cout<<"-1\n";
    }else{
        int odd=1;int even=2;int oddflag=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(oddflag){
                    cout<<odd<<" ";
                    odd+=2;
                    if(odd>(n*n)){
                        oddflag=0;
                    }
                }else{
                    cout<<even<<" ";
                    even+=2;
                }
            }
            cout<<"\n";
        }
    }
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}