#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<pair<long long,long long>>task(n);
    for(long long i=0;i<n;i++)
    {
        cin>>task[i].first>>task[i].second;
    }

    sort(task.begin(),task.end(),[&](const pair<long long,long long>&a,const pair<long long,long long>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    });


    long long profit=0;
    long long chal=0;
    for(long long i=0;i<n;i++){
        chal+=task[i].first;
        profit+=(task[i].second-chal);
    }
    cout<<profit<<"\n";
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}