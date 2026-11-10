#include <bits/stdc++.h>
#define int long long
using namespace std;
class SegTree{
    vector<int>tree;
    int n;
    public:
    SegTree(int n):n(n),tree(4*n,0){}
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
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
    void build(int idx,int start,int end,vector<int>&arr){
        if(start==end){
            tree[idx]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(2*idx,start,mid,arr);
        build(2*idx+1,mid+1,end,arr);
        tree[idx]=min(tree[idx*2],tree[2*idx+1]);
    }
    int query(int idx,int start,int end,int l,int r){
        if(l>end or r<start){
            return 1e18;
        }
        if(start>=l and r>=end){
            return tree[idx];
        }
        int mid=start+(end-start)/2;
        return min(query(2*idx,start,mid,l,r),query(2*idx+1,mid+1,end,l,r));
    }
    void build(vector<int>&arr){
        build(1,0,n-1,arr);
    }
    void update(int pos,int del){
        update(1,0,n-1,pos,del);

    }
    int query(int l,int r){
        return query(1,0,n-1,l,r);
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    SegTree st(n);
    st.build(a);
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int pos,del;
            cin>>pos>>del;
            pos--;
            st.update(pos,del);
        }else{
            int l;
            int r;
            cin>>l>>r;
            l--;
            r--;
            cout<<st.query(l,r)<<"\n";
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}