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


// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int>a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     //i have to retuern n-k+1; elm from L to R of each k elm 
//     // BF   ---->  
//     // for(int i=0;i<(n-k+1);i++)
//     // {
//     //     vector<int>arr;
//     //     for(int j=i;j<i+k;j++)
//     //     {
//     //         arr.push_back(a[j]);
//     //     }
//     //     sort(all(arr));
//     //     cout<<arr[k/2]<<" ";
//     // }
//     //what can i do? will move k forward and remove the start pos elm and add in some kind of stuff which will give me median 
//     for(int i=0;i<n;i++)
//     {

//     }
//     cout<<"\n";
// }
void addE(int x, multiset<int> &low, multiset<int> &high)
{
    if (low.empty() || x <= *prev(low.end()))
        low.insert(x);
    else
        high.insert(x);
}

void delE(int x, multiset<int> &low, multiset<int> &high)
{
    auto it = low.find(x);

    if (it != low.end())
        low.erase(it);
    else
        high.erase(high.find(x));
}

void balanceE(multiset<int> &low, multiset<int> &high)
{
    // low should have either same size as high
    // or exactly one more

    while (low.size() > high.size() + 1)
    {
        auto it = prev(low.end());

        high.insert(*it);

        low.erase(it);
    }

    while (low.size() < high.size())
    {
        auto it = high.begin();

        low.insert(*it);

        high.erase(it);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    multiset<int> low, high;

    for (int i = 0; i < n; i++)
    {
        addE(arr[i], low, high);

        balanceE(low, high);

        // window exceeds k
        if (i >= k)
        {
            delE(arr[i - k], low, high);

            balanceE(low, high);
        }

        // window ready
        if (i >= k - 1)
        {
            cout << *prev(low.end()) << " ";
        }
    }

    cout << "\n";
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





 