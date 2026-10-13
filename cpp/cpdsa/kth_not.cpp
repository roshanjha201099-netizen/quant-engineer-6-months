#include <bits/stdc++.h>
using namespace std;


void solve(){

    long long n;
    long long k;
    cin>>n>>k;
    long long cal=k/(n-1);
    long long rem=k%(n-1);
    long long val=cal*n;
    if(rem==0){
        val-=1;
    }else{
        val+=rem;
    }
    cout<<val<<"\n";

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}