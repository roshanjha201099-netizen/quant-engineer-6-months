#include <bits/stdc++.h> 
using namespace std;

bool sumOfD(int x,int a,int b){
    int sum=0;
    while(x){
        int rem=x%10;
        sum+=rem;
        x=x/10;
    }
    return (sum>=a and sum<=b);
}

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    long long sum=0;
    for(int i=1;i<=n;i++){
        if(sumOfD(i,a,b)){
            sum+=i;
        }
    }
    cout<<sum<<"\n";
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}