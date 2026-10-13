#include<bits/stdc++.h>
using namespace std;

#define roshanfyou ios::sync_with_stdio(false);cin.tie(nullptr);
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            if(i==0)cin>>a[j];
            else cin>>b[j];
        }
    }
    int sum=0LL;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),[&](int x,int y){
        return x>y;
    });

    int i=0;
    while(k--){
        if(a[i]>=b[i])break;
        swap(a[i],b[i]);
        i++;
    }
    for(auto &x:a)sum+=x;
    cout<<sum<<"\n";
}
int32_t main(){
    roshanfyou;
    int t=1;
    cin>>t;
    while(t--){solve();}
    return 0;
}