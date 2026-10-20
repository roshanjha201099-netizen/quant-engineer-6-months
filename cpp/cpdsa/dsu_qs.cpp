#include <bits/stdc++.h>
using namespace std;

#define int long long

class DSU{
    vector<int>par,sz;
    int max_size;
    set<int>comp;
    public:
    DSU(int n){
        max_size=1;
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;
            comp.insert(i);
            sz[i]=1;
        }
    }
    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
    bool unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return false;
        if(sz[x]<sz[y])swap(x,y);
        par[y]=x;
        comp.erase(y);
        sz[x]+=sz[y];
        max_size=max(max_size,sz[x]);
        return true;
    }
    bool connected(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
    int max_size_comp(){
        return max_size;
    }
    int num_components(){
        return comp.size();
    }
};


void roadDestruct(){
    int n,m,q;
    cin>>n>>m>>q;
    map<pair<int,int>,int>mp;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        mp[{u,v}]=1;
    }
    vector<pair<int,int>>query(q);
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        if(mp.find({x,y})!=mp.end()){
            mp.erase({x,y});
        }
        query[i]={x,y};
    }
    reverse(query.begin(),query.end());
    DSU dsu(n);
    for(auto x:mp){
        dsu.unite(x.first.first,x.first.second);
    }
    vector<int>ans;
    for(auto x:query){
        ans.push_back(dsu.num_components());
        dsu.unite(x.first,x.second);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<"\n";
}


void solve2(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(m);
    for(int i=0;i<m;i++){
        int u,v,y;
        cin>>u>>v>>y;
        graph[i]={u,v,y};
    }
    sort(graph.begin(),graph.end(),[&](vector<int>&a,vector<int>&b){
        return a[2]>b[2];
    });
    int w;
    cin>>w;
    vector<vector<int>>q(w);
    for(int i=0;i<w;i++){
        int x,y;
        cin>>x>>y;
        q[i]={x,y,i};
    }
    sort(q.begin(),q.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    });
    vector<int>ans(w);
    DSU dsu(n);
    int j=0;
    for(auto x:q){
        int city=x[0];
        int yr=x[1];
        int idx=x[2];
        while(j<m && graph[j][2]>yr){
            dsu.unite(graph[j][0],graph[j][1]);
            j++;
        }
        ans[idx]=dsu.size(city);
    }
    for(int i=0;i<w;i++){
        cout<<ans[i]<<"\n";
    }
}
void news_dist() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;

        int prev = -1;

        for (int j = 0; j < a; j++) {
            int x;
            cin >> x;

            if (prev != -1) {
                dsu.unite(prev, x);
            }

            prev = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dsu.size(i) << " ";
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        dsu.unite(u,v);
        cout<<dsu.num_components()<<" "<<dsu.max_size_comp()<<"\n";
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    news_dist();
    return 0;
}