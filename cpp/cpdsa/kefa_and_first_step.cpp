#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    vector<int>mo(n);
    for(int i=0;i<n;i++)
    {
        cin>>mo[i];
    }
    int cnt=1;
    int maxi=1;
    for(int i=1;i<n;i++){
        if(mo[i]>=mo[i-1]){
            cnt++;
        }else{
            maxi=max(maxi,cnt);
            cnt=1;
        }
    }
    maxi=max(cnt,maxi);
    cout<<maxi<<"\n";
}
// 6
// 2 2 1 3 4 1

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}