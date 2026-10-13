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
void solve()
{
    int n;
    cin >> n;

    struct Customer
    {
        int arrival, departure, index;
    };

    vector<Customer> customers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;
    }

    sort(customers.begin(), customers.end(),
         [](Customer &a, Customer &b)
         {
             return a.arrival < b.arrival;
         });

    // {departure time, room number}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> ans(n);

    int rooms = 0;

    for (auto &c : customers)
    {
        if (pq.empty() || pq.top().first >= c.arrival)
        {
            rooms++;
            ans[c.index] = rooms;
            pq.push({c.departure, rooms});
        }
        else
        {
            auto [dep, roomNo] = pq.top();
            pq.pop();

            ans[c.index] = roomNo;
            pq.push({c.departure, roomNo});
        }
    }

    cout << rooms << "\n";

    for (int x : ans)
        cout << x << " ";

    cout << "\n";
}


// {
//     int n;
//     cin>>n;
//     vector<pair<int,int>>arr(n);
//     for(int i=0;i<n;i++)
//     {
//         int a,b;
//         cin>>a>>b;
//         a[i]={a,b};
//     }
//     // sort(all(arr));
//     map<pair<int,int>,int>mp;
//     mp[{arr[0].first,mp[1].second}]=1;
//     for(int i=1;i<n;i++)
//     {
//         //1,2->1
//         //2,4->2
//         //4,4-->1(because when i iterated i got something which is less than it)
//         for(int )

//     }
// }
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





 