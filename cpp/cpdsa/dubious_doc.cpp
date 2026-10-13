#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(string x, string y) {
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '?' || x[i] == y[i]) {
            
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    if (s.find(t) == string::npos) {
        vector<int> pos;

        for (int i = 0; i <= n - m; i++) {
            if (check(s.substr(i, t.size()), t)) {
                pos.push_back(i);
            }
        }

        if (pos.size() == 0) {
            cout << "UNRESTORABLE\n";
        } 
        else {
            int lp = pos[pos.size() - 1];

            for (int i = 0; i < s.size(); i++) {

                if (i >= lp && i < lp + m) {

                    int j=0;
                    while(j<m){
                        s[i+j]=t[j];
                        j++;
                    }
                    i=i+j-1;

                } 
                else if (s[i] == '?') {
                    s[i] = 'a';
                }
            }

            cout << s << "\n";
        }

    } 
    else {

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                s[i] = 'a';
            }
        }

        cout << s << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}