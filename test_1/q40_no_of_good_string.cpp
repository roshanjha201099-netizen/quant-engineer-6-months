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

//000011100001 --->if i count all one than for 2 i have to chk 10 for 3  011 for 4 0100  for 5 00101 000110 for 6 but again its time complexity will be much more 
// idk at this point apart from brute force and also bf mein bhi issue nikli so first lkests fix that  



int string_to_dec(string s) {
    int no = 0;

    for (char digit : s) {
        no = no * 2 + (digit - '0');
    }
    return no;
}

//okay 20 bits makes sense but when i find one 1 in it what should i check ?
//like 000110----->this makes sense 
// //if somehow i can keep the track how much zero is behnind it 1 10 (011)here i needed extra zero at back to make it 3 0100 here again 00101 but how to keep track of it ?
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    // lastOne[i] = last index of '1' before or at i
    vector<int> lastOne(n);

    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            last = i;

        lastOne[i] = last;
    }

    int ans = 0;

    for (int r = 0; r < n; r++)
    {
        int value = 0;

        // only last 20 bits
        for (int l = r; l >= 0 && r - l + 1 <= 20; l--)
        {
            if (s[l] == '1')
                value += (1LL << (r - l));

            if (value == 0)
                continue;

            int len = r - l + 1;

            if (value < len)
                continue;

            int need = value - len;

            int prevOne = (l == 0 ? -1 : lastOne[l - 1]);

            int zerosAvailable = l - prevOne - 1;

            if (need <= zerosAvailable)
                ans++;
        }
    }

    cout << ans << "\n";
}




int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
//i will be strongest .





 