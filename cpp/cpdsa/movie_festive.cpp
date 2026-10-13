#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    a.reserve(n);
    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        a.push_back({s,e});
    }
    sort(a.begin(), a.end(), [](const pair<int,int>& now, const pair<int,int>& o){
        return now.second < o.second;
    });

    int cnt=1;
    int prev=a[0].second;

    for(int i=1;i<n;i++)
    {
        if(prev<=a[i].first)
        {
            cnt++;
            prev=max(prev,a[i].second);
        }
    }
    cout<<cnt<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
     
    cin.tie(nullptr);

    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}