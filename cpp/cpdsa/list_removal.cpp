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
        if(mid>=pos){
            update(idx*2,start,mid,pos,del);
        }else{

            update(1+idx*2,mid+1,end,pos,del);
        }
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
    void build(int idx,int start,int end,vector<int>&arr){
        if(start==end){
            tree[idx]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(idx*2,start,mid,arr);
        build(2*idx+1,mid+1,end,arr);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
    int query(int idx,int start,int end,int k){
        if(start==end){
            return start;
        }
        int mid=start+(end-start)/2;
        if(tree[2*idx]>=k){
            return query(2*idx,start,mid,k);
        }else{
            return query(2*idx+1,mid+1,end,k-tree[2*idx]);
        }
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),alive(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        alive[i]=1;
    }
    SegmentTree st(n);
    st.build(1,0,n-1,alive);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int pos = st.query(1,0,n-1,k);

        cout << a[pos] << " ";

        st.update(1,0,n-1,pos,0);
    }


}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
