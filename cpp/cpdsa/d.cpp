#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N = 9999999;
vector<bool> isPrime(N + 1, true);
void fxn(){
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= N; p++) {
        if (isPrime[p]) {
            for (int x = p * p; x <= N; x += p) {
                isPrime[x] = false;
            }
        }
    }
}
bool check(string s, int i)
{
    string t = to_string(i);

    map<char, vector<int>> mp;
    map<char, vector<int>> mp1;

    for (int id = 0; id < s.size(); id++)
    {
        mp[s[id]].push_back(id);
        mp1[t[id]].push_back(id);
    }

  
    for (auto &[ch, pos] : mp)
    {
        char digit = t[pos[0]];

        if (mp1[digit] != pos)
            return false;
    }

 
    for (auto &[digit, pos] : mp1)
    {
        char ch = s[pos[0]];

        if (mp[ch] != pos)
            return false;
    }

    return true;
}
void solve()
{
    string s;
    cin>>s;

    int len=s.size();
    
    for(int i=pow(10,len-1);i<(pow(10,len));i++)
    {
       
        if(isPrime[i]){
            if(check(s,i)){
                cout<<i<<"\n";
                return;
            }
        }
    }
    cout<<"-1\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fxn();
    
        solve();
    
    return 0;
}