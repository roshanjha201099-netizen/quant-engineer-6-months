#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

bool valid(long long x,long long c,vector<long long>&arr){
    long long cnt=1;
    long long fc=arr[0];
    for (int  i = 1; i <arr.size(); i++)
    {
        if((arr[i]-fc)>=x){
            cnt++;
            fc=arr[i];
        }
    }
    return cnt>=c;
}
// 1
// 5 3
// 1 2 8 4 9==>1 2 4 8 9
void solve(){
    long long  n,c;
    cin>>n>>c;
    vector<long long >p(n);
    for(auto &a:p)cin>>a;
    sort(all(p));
    long long  lo=1;
    long long  hi=p[n-1]-p[0];
    
    long long  ans=hi;
    while(lo<=hi){

        long long  mi=(lo+(hi-lo)/2);
        if(valid(mi,c,p)){
            ans=mi;
            lo=mi+1;
        }else{
            hi=mi-1;
        }
    }
    cout<<ans<<"\n";

}

int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    while(t--)solve();
    return 0;

}