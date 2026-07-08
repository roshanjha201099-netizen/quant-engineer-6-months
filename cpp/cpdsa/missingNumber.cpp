#include<bits/stdc++.h> 
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


//okay so here we have to find the missing number 
// 1) we can use array to store the number and sort it 
// 2)find sum of all number - n*(n+1)/2
// 3)we can use xor to find the missing number a xor a =0
// 4)we can use sets to check the missing number
// 5)we can use hash map to check the missing number
// 6)we can use binary search to find the missing number

void solve1(){
    int n;
    cin>>n;
    vector<int>a(n-1);
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    sort(all(a));
    for(int i=0;i<n-1;i++){
        if(a[i]!=i+1){
            cout<<i+1<<"\n";
            return;
        }
    }
    cout<<n<<"\n";
}
void solve2(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n-1;i++){
        int num;
        cin>>num;
        sum+=num;
    }
    int expected_sum=n*(n+1)/2;
    cout<<expected_sum-sum<<"\n";
}
void solve3(){
    int n;
    cin>>n;
    int xor1=0;
    int xor2=0;
    for(int i=0;i<n-1;i++){
        int num;
        cin>>num;
        xor1^=num;
    }
    for(int i=1;i<=n;i++){
        xor2^=i;
    }
    cout<<(xor1^xor2)<<"\n";
}
void solve4(){
    int n;
    cin>>n;
    set<int>s;
    for(int i=0;i<n-1;i++)
    {
        int nu;
        cin>>nu;
        s.insert(nu);
    }
    for(int i=1;i<=n;i++)
    {
        if(s.find(i)!=s.end()){
            continue;
        }
        else
        {cout<<i<<"\n";return;}
    }
}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--) {
        solve4();
    }
    return 0;
}
//i will be strongest .





 