//  Otoshidama.cpp

#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,y;
  cin>>n>>y;
  for(int a=0;a<=2000;a++){
    for(int b=0;b<=4000;b++){
      int val=a*10000+b*5000;
      int c1=(y-val)/1000;
      int c2=n-(a+b);
      if(c1==c2 and (a>=0 and b>=0 and (n-(a+b))>=0)){
        cout<<a<<" "<<b<<" "<<(n-(a+b))<<"\n";
        return;
      }
    }
  }
  cout<<"-1 -1 -1\n";
}
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}