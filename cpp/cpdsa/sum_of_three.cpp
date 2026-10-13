#include <bits/stdc++.h>
using namespace std;
 

 
 
const int M = 1e9 + 7;
#define int long long
#define all(a) (a).begin(), (a).end()
using pii = pair<int, int>;

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=arr[i]+arr[j];
            if(mp.find(x-sum)!=mp.end())
            {
                cout<<i+1<<" "<<j+1<<" "<<mp[x-sum]+1<<"\n";
                return;
            }
        }
        mp[arr[i]]=i;
    }
    cout<<"IMPOSSIBLE\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
//i will be strongest .


