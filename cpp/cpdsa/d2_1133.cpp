
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
   int n;
   cin>>n;
   vector<int>a(n);
   for(int &x:a)cin>>x;

   int maxDiff=-1e9;
   bool right=true;
   int l=-1;
   int nowith=-1;

   for(int i=0;i<n-1;i++){
    int n1=a[i];
    int n2=a[i+1];
    int diff=abs(n2-n1);

    if(diff>maxDiff){
        maxDiff=diff;
        if(n1<n2){
            l=i;
            nowith=a[i+1];
            right=false;
        }else{
            l=i+1;
            nowith=a[i];
            right=true;
        }
    }
   }

   if(right){
    int mini=maxDiff;
    int at=-1;

    for(int i=l;i<n;i++){
        int diff=abs(nowith-2*a[i]);
        if(diff>mini){
            mini=diff;
            at=i;
        }
    }

    if(at==-1){
        cout<<maxDiff<<"\n";
    }else{
        int i=l,j=at;

        while(i<j){
            swap(a[i],a[j]);
            a[i]*=2;
            a[j]*=2;
            i++;
            j--;
        }

        if(i==j){
            a[i]*=2;
        }

        int ans=1e18;
        for(int i=0;i<n-1;i++){
            int diff=abs(a[i]-a[i+1]);
            ans=max(ans,diff);
        }
        cout<<ans<<"\n";
    }

   }else{
      int mini=maxDiff;
      int at=-1;

      for(int i=l;i>=0;i--){
        int diff=abs(nowith-2*a[i]);
        if(diff>mini){
            mini=diff;
            at=i;
        }
      }

      if(at==-1){
        cout<<maxDiff<<"\n";
      }else{
        int i=at,j=l;

        while(i<j){
            swap(a[i],a[j]);
            a[i]*=2;
            a[j]*=2;
            i++;
            j--;
        }

        if(i==j){
            a[i]*=2;
        }

        int ans=1e18;
        for(int i=0;i<n-1;i++){
            int diff=abs(a[i]-a[i+1]);
            ans=max(ans,diff);
        }
        cout<<ans<<"\n";
      }
   }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
