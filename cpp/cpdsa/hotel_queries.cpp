#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree{
    vector<int>tree;
    int n;
    public:
    SegmentTree(int n):n(n),tree(4*n,0){}
    void update(int idx,int start,int end,int pos,int del){
        if(start==end){
            tree[idx]=del;
            return;
        }
        int mid=start+(end-start)/2;
        if(pos<=mid){
            update(2*idx,start,mid,pos,del);
        }else{
            update(2*idx+1,mid+1,end,pos,del);
        }
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
    void build(int idx,int start,int end,vector<int>&arr){
        if(start==end){
            tree[idx]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(idx*2,start,mid,arr);
        build(2*idx+1,mid+1,end,arr);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
    int query(int idx, int start, int end, int val) {
        if (tree[idx] < val) return -1;

        if (start == end) return start;

        int mid = start + (end-start)/2;

        if (tree[2*idx] >= val) {
            return query(2*idx, start, mid, val);
        }

        return query(2*idx+1, mid+1, end, val);
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int &x:arr)cin>>x;
    SegmentTree st(n);
    st.build(1,0,n-1,arr);
    while(m--){
        int val;
        cin>>val;
        auto ans=st.query(1,0,n-1,val);
        if(ans==-1){
            cout<<0<<" ";
        }else{
            int newval=arr[ans]-val;
            arr[ans]=newval;
            st.update(1,0,n-1,ans,newval);
            cout<<ans+1<<" ";
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}