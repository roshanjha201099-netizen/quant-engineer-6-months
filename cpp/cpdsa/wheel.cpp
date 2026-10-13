#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>wt(n);
    for(int i=0;i<n;i++)cin>>wt[i];
    int cnt=0;
    sort(wt.begin(),wt.end());
    int i=0;
    int j=n-1;
    while(i<=j){
        if(i==j){
            cnt++;
            break;
        }
        if(wt[i]+wt[j]<=x){
            int tot=wt[i]+wt[j];
            j--;
            i++;
            cnt++;
        }else if(wt[i]+wt[j]>x){
            j--;
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}

int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;

}
