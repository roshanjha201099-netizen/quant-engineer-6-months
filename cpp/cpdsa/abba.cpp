#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            t+='a';
        }
        else
        {
            t+='b';
        }
    }
    int l=0,r=n-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            if(t[l]==t[r])
            {
                l++;
            }else
            {
                if(t[l]=='a')
                {
                    if(s[i+1]=='a'){
                        r--;
                    }else if(s[i+1]=='b'){
                        l++;
                    }
                }else
                {
                    if(s[i+1]=='a'){
                        l++;
                    }else if(s[i+1]=='b'){
                        r--;
                    }
            }
        }}else if(s[i]!='?')
        {
            if(s[i]==t[l])l++;
            else if(s[i]==t[r])r--;
            else
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}