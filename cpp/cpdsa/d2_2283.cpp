#include <bits/stdc++.h>
using namespace std;

#define int long long
class FenwickTree {
    
    vector<int> bit;  // binary indexed tree
    int n;
    public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }
    void update(int idx,int del){
        while(idx<=n){
            bit[idx]+=del;
            idx+=(idx&-idx);
        }
    }
    int query(int idx){
        int sum=0;
        while(idx>0){
            sum+=bit[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int>depth(n+1);
    int ep1=-1;
    int maxDepth=-1e9;
    function<void(int,int)> dfs = [&](int u,int p) {
        if(maxDepth<depth[u]){
            maxDepth=depth[u];
            ep1=u;
        }
        for(auto v:tree[u]) {
            if(v==p) continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    };
    depth[1]=0;
    dfs(1,0);
    maxDepth=-1e9;
    int ep2=-1;
    depth.assign(n+1,0);
    vector<int>dist1(n+1);
    function<void(int,int)>dfs2=[&](int u,int p) {
        dist1[u]=depth[u];
        if(maxDepth<depth[u]){
            maxDepth=depth[u];
            ep2=u;
        }
        for(auto v:tree[u]) {
            if(v==p) continue;
            depth[v]=depth[u]+1;
            dfs2(v,u);
        }
    };
    dist1[ep1]=0;
    depth[ep1]=0;
    dfs2(ep1,0);
    vector<int>dist2(n+1);
    depth.assign(n+1,0);
    function<void(int,int)>dfs3=[&](int u,int p) {
        dist2[u]=depth[u];
        for(auto v:tree[u]) {
            if(v==p) continue;
            depth[v]=depth[u]+1;
            dfs3(v,u);
        }
    };
    dist2[ep2]=0;
    depth[ep2]=0;
    dfs3(ep2,0);
    for(int i=1;i<=n;i++) {
        cout << max(dist1[i],dist2[i]) << " ";
    }
  
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}