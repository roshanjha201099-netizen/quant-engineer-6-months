#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int lowerBound(vector<int>&arr,int tar){
    int lo=0;
    int hi=arr.size()-1;
    int ans=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)>>1;
        if(arr[mid]>=tar)
        {
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int>&arr,int tar){
    int lo=0;
    int hi=arr.size()-1;
    int ans=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)>>1;
        if(arr[mid]>tar)
        {
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans;
}
bool isValid(int cap,const vector<int>& wt, int d){
        int tot=0;
        for(int i=0;i<wt.size();i++)
            {
                int sum=0;
                while(i<wt.size() and sum+wt[i]<=cap){
                    sum+=wt[i];
                    i++;
                }
                tot++;
            }
        return tot<=d;
    }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int>arr={1,2,3,3,4,4,4,6,7};
    int tar=4;
    // cout<<upperBound(arr,tar)-1;
    cout<<isValid(14,{1,2,3,4,5,6,7,8,9,10},5)<<"\n";
    return 0;
}