#include <bits/stdc++.h>
using namespace std;
 
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 8
#endif
 
 
const int M = 1e9 + 7;
#define int long long
#define all(a) (a).begin(), (a).end()
using pii = pair<int, int>;
// multiset<int> ms;
struct Pair
{
    int index;
    int value;

    bool operator<(const Pair& other) const {
        if (index != other.index) {
            return index < other.index;
        }

        return value > other.value;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    stack<int>st;
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        while(!st.empty() and arr[st.top()]>=arr[i])st.pop();
        if(st.empty())ans[i]=0;
        else ans[i]=st.top()+1;
        st.push(i);
    }
    for(auto x:ans)cout<<x<<" ";
    cout<<"\n";
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





 
