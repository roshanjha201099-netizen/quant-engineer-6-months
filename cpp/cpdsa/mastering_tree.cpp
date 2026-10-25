#include <bits/stdc++.h>
using namespace std;

#define int long long

void coordinator(){
    int n;
    cin>>n;
    vector<vector<int>>tree(n+1);
    for(int i=2;i<=n;i++){
        int boss;
        cin>>boss;
        tree[boss].push_back(i);
        tree[i].push_back(boss);
    }
    vector<int>ans(n+1);
    function<int(int,int)>dfs=[&](int node,int par){
        int sub=0;
        for(auto x:tree[node]){
            if(x==par)continue;
            sub+=dfs(x,node)+1;
        }
        ans[node]=sub;
        return sub;
    };
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}


void matching_tree() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    function<void(int, int)> dfs = [&](int u, int par) {
        for (auto v : tree[u]) {
            if (v == par) continue;
            dfs(v, u);
        }

        for (auto v : tree[u]) {
            if (v == par) continue;
            dp[u][1] += dp[v][0];
        }

        dp[u][0] = dp[u][1];

        for (auto v : tree[u]) 
        {
            if (v == par) continue;

            int can = dp[u][1] - dp[v][0] + dp[v][1] + 1;
            dp[u][0] = max(dp[u][0], can);
        }
    };

    dfs(1, 0);
    cout << dp[1][0] << "\n";
}

void diameter(){
    int n;
    int m;
    cin>>n;
    m=n-1;
    vector<vector<int>>tree(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int>dist(n+1,0);
    int maxD=-1e9;
    int farthestNode=1;
    function<void(int,int)>dfs=[&](int u,int p){
        if(dist[u]>maxD){
            maxD=dist[u];
            farthestNode=u;
        }
        for(auto v:tree[u]){
            if(v==p)continue;
            dist[v]=dist[u]+1;
            dfs(v,u);
        }
    };
    dfs(1,0);
    dist[farthestNode]=0;
    maxD=-1e9;
    dfs(farthestNode,0);
    cout<<maxD<<"\n";
}

void tree_dist_one(){
    int n;
    cin>>n;
    vector<vector<int>>tree(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int ep=-1;
    int maxD=-1e9;
    vector<int>dist(n+1);

    function<void(int,int)>dfs=[&](int u,int p){
        if(maxD<dist[u]){
            maxD=dist[u];
            ep=u;
        }
        for(auto v:tree[u]){
            if(v==p)continue;
            dist[v]=dist[u]+1;
            dfs(v,u);
        }
    };
    dist[1]=0;
    dfs(1,0);
    //so ep=x something now from that get to another ep
    vector<int>distEp1(n+1);
    int ep2=-1;
    int maxiD2=-1e9;
    function<void(int,int)>dfs1=[&](int u,int p){
        if(maxiD2<distEp1[u]){
           maxiD2= distEp1[u];
           ep2=u;
        }
        for(auto v:tree[u]){
            if(v==p)continue;
            distEp1[v]=distEp1[u]+1;
            dfs1(v,u);
        }
    };
    distEp1[ep]=0;
    dfs1(ep,0);
    vector<int>distEp2(n+1);
    function<void(int,int)>dfs2=[&](int u,int p){
        for(auto v:tree[u]){
            if(v==p)continue;
            distEp2[v]=distEp2[u]+1;
            dfs2(v,u);
        }
    };
    distEp2[ep2]=0;
    dfs2(ep2,0);
    for(int i=1;i<=n;i++){
        cout<<max(distEp2[i],distEp1[i])<<" ";
    }
    cout<<"\n";
}

void tree_dist_two(){
    int n;
    cin>>n;
    vector<vector<int>>tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int>subtree(n+1);
    function<int(int,int)>dfs=[&](int u,int p){
        int sz=1;
        for(int v:tree[u]){
            if(v==p)continue;
            sz+=dfs(v,u);
        }
        subtree[u]=sz;
        return sz;
    };
    dfs(1,0);
    vector<int>ans(n+1);
    //now i have to calculate the distToEachNodeSum for 1 
    function<void(int,int,int)>dfs2=[&](int u,int p,int d){
        ans[1]+=d;
        for(auto v:tree[u]){
            if(v==p)continue;
            dfs2(v,u,d+1);
        }
    };
    dfs2(1,0,0);

    function<void(int,int)>dfs3=[&](int u,int p){
        for(auto v:tree[u]){
          if(v==p)continue;
          ans[v]=ans[u]+n-2*subtree[v];
          dfs3(v,u);
        }
    };
    dfs3(1,0);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

void comapany_query_one(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>>tree(n+1);
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        tree[p].push_back(i);
        tree[i].push_back(p);
    }
    //dfs for getting everyone parents
    vector<int>par(n+1);
    function<void(int,int)>dfs=[&](int u,int p){
        par[u]=p;
        for(int v:tree[u]){
            if(v==p)continue;
            dfs(v,u);
        }
    };
    dfs(1,0);
    const int LOG=22;
    vector<vector<int>>up(n+1,vector<int>(LOG,0));
    for(int i = 1; i <= n; i++){
        up[i][0] = par[i];
    }
    for(int i=1;i<LOG;i++){
        for(int j=1;j<=n;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
    while(q--){
        int e,k;
        cin>>e>>k;
        
        for (size_t i = 0; i < LOG; i++)
        {
            if(k&(1<<i)){
                e=up[e][i];
            }
        }
        if(e==0){
            cout<<"-1\n";
        }else{
            cout<<e<<"\n";
        }
    }

}

void company_query_two(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>>tree(n+1);
    for(int i=2;i<=n;i++){
        int b;
        cin>>b;
        tree[b].push_back(i);
        tree[i].push_back(b);
    }
    vector<int>par(n+1);
    vector<int>depth(n+1);
    function<void(int,int)>dfs=[&](int u,int p){
        par[u]=p;
        for(int v:tree[u]){
            if(v==p)continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    };
    dfs(1,0);
    
    const int LOG=22;
    
    vector<vector<int>>up(n+1,vector<int>(22,0));
    
    for(int i=1;i<=n;i++){
        up[i][0]=par[i];
    }
    
    for(int j=1;j<LOG;j++)
    {

        for(int i=1;i<=n;i++)
        {
     
            up[i][j]=up[up[i][j-1]][j-1];
     
        }
    
    }

    while(q--){
        int a,b;
        cin>>a>>b;
     
        if(depth[a]<depth[b]){
            swap(a,b);
        }
        int diff=depth[a]-depth[b];
        for(int i=0;i<LOG;i++){
            if(diff&(1<<i)){
                a=up[a][i];
            }
        }
        if(a==b){
            cout<<a<<"\n";
            continue;
        }

        for(int i=LOG-1;i>=0;i--){
            if(up[a][i]!=up[b][i]){
                a=up[a][i];
                b=up[b][i];
            }
        }
        cout<<up[a][0]<<"\n";
    }
}


void distance_queries() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> tree(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> depth(n + 1);
    vector<int> par(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        par[u] = p;

        for (int v : tree[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    };

    dfs(1, 0);

    const int LOG = 22;
    vector<vector<int>> up(n + 1, vector<int>(LOG, 0));

    for (int i = 1; i <= n; i++) {
        up[i][0] = par[i];
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        int original_u = u;
        int original_v = v;

        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i)) {
                u = up[u][i];
            }
        }

        int lca;

        if (u == v) {
            lca = u;
        } else {
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            lca = up[u][0];
        }

        int ans = depth[original_u] + depth[original_v]
                - 2 * depth[lca];

        cout << ans << '\n';
    }
}

void counting_path(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int>par(n+1),depth(n+1);
    function<void(int,int)>dfs=[&](int u,int p){
        par[u]=p;
        for(int v:tree[u]){
            if(v==p)continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    };
    dfs(1,0);
    const int LOG=22;
    vector<vector<int>>up(n+1,vector<int>(22));
    for(int i=1;i<=n;i++){
        up[i][0]=par[i];
    }
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    vector<int>cnt(n+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        int og_a=a;
        int og_b=b;
        if(depth[a]<depth[b]){
            swap(a,b);
        }
        int diff=depth[a]-depth[b];
        for(int i=0;i<LOG;i++){
            if(diff & (1<<i)){
                a=up[a][i];
            }
        }
        int lca;
        if(a==b){
            lca=a;
        }else{
            for(int i=LOG-1;i>=0;i--){
                if(up[a][i]!=up[b][i]){
                    a=up[a][i];
                    b=up[b][i];
                }
            }
            lca=up[a][0];
        }
        cnt[og_a]++;
        cnt[og_b]++;
        cnt[lca]--;
        cnt[par[lca]]--;
    }
    function<void(int,int)>dfs2=[&](int u,int p){
        for(int v:tree[u]){
            if(v==p)continue;
            dfs2(v,u);
            cnt[u]+=cnt[v];
        }
    };
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";

}


class FenwickTree{
    int n;
    vector<int>bits;
    public:
    FenwickTree(int n){
        this->n=n;
        bits.assign(n+1,0);
    }
    void update(int idx,int delta){
        while(idx<=n){
            bits[idx]+=delta;
            idx+=idx & -idx;
        }
    }
    int query(int idx){
        int sum=0;
        while(idx>0){
            sum+=bits[idx];
            idx-=idx & -idx;
        }
        return sum;
    }
    int range_query(int l,int r)
    {
        return query(r) - query(l-1);
    }
};



void subtree_queries(){
    int n,q;
    cin>>n>>q;
    vector<int>val(n+1);
    vector<vector<int>>tree(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int>arr(n+1),tin(n+1),tout(n+1);
    int timer=0;
    function<void(int,int)>dfs=[&](int u,int p){
        tin[u]=++timer;
        arr[timer]=val[u];
        for(int v:tree[u]){
            if(v==p)continue;
            dfs(v,u);
        }
        tout[u]=timer;
    };
    dfs(1,0);
    FenwickTree fw(n);
    for(int i = 1; i <= n; i++) {
        fw.update(i, arr[i]);
    }
    while(q--){
        int type,s;
        cin>>type>>s;
        if(type==1){
            int x;
            cin>>x;
            int delta=x-val[s];
            val[s]=x;
            fw.update(tin[s],delta);
        }else{
            cout<<fw.range_query(tin[s],tout[s])<<"\n";
        }
    }
}

void path_query(){
    int n,m;
    cin>>n>>m;
    vector<int>val(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    vector<vector<int>>tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int>arr(n+1),tin(n+1),tout(n+1);
    int timer=0;
    function<void(int,int)>dfs=[&](int u,int p){
        tin[u]=++timer;
        arr[timer]=val[u];
        for(int v:tree[u]){
            if(p==v)continue;
            dfs(v,u);
        }
        tout[u]=timer;
    };
    dfs(1,0);
    FenwickTree fw(n);
    for(int u=1;u<=n;u++)
    {

        fw.update(tin[u],val[u]);
        fw.update(tout[u]+1,-val[u]);

    }
    while(m--){
        int type,no;
        cin>>type>>no;
        if(type==1){
            int nv;
            cin>>nv;
            int delta=nv-val[no];
            val[no]=nv;
            fw.update(tin[no],delta);
            fw.update(tout[no]+1,-delta);
        }else{
            cout<<fw.query(tin[no])<<"\n";
        }
    }

}


class DSU{
    vector<int>par,sz,dist_col;
    int max_size;
    set<int>comp;
    public:
    DSU(int n){
        max_size=1;
        par.resize(n+1);
        sz.resize(n+1);
        dist_col.resize(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;
            dist_col[i]=1;
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

void distinct_color(){
    int n;
    cin>>n;
    vector<int>node_color(n+1);
    for(int i=1;i<=n;i++){
        cin>>node_color[i];
    }
    vector<vector<int>>tree(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<set<int>>st(n+1);
    vector<int>ans(n+1);
    function<void(int,int)>dfs=[&](int u,int p){
        st[u].insert(node_color[u]);
        for(auto v:tree[u]){
            if(v==p)continue;
            dfs(v,u);
            if (st[u].size() < st[v].size()) {
                swap(st[u], st[v]);
            }
            for (int c : st[v]) {
                st[u].insert(c);
            }
        }
        ans[u]=st[u].size();
    };
    dfs(1, 0);  // Missing DFS call

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
   

}

void tree_painting(){
    int n;
    cin>>n;
    vector<vector<int>>tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int>subtree(n+1);
    function<int(int,int)>dfs=[&](int u,int p){
        int sz=1;
        for(int v:tree[u]){
            if(v==p)continue;
            sz+=dfs(v,u);
        }
        subtree[u]=sz;
        return sz;
    };
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<subtree[i]<<" ";
    }
}

void party() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    vector<int> roots;

    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;

        if (e == -1) {
            roots.push_back(i);
        } else {
            tree[e].push_back(i);
        }
    }

    int maxi = 0;

    function<void(int, int)> dfs = [&](int u, int d) {
        maxi = max(maxi, d);

        for (auto v : tree[u]) {
            dfs(v, d + 1);
        }
    };

    for (auto e : roots) {
        dfs(e, 1);
    }

    cout << maxi << "\n";
}

void expected_length_journey() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    double ans = 0.0;

    function<void(int, int, double, int)> dfs =
    [&](int u, int p, double pb, int dep) {
        int size = tree[u].size();

        // Root itself is a leaf if n == 1.
        if (n == 1) {
            return;
        }

        // Non-root leaf: only neighbour is its parent.
        if (u != 1 && size == 1) {
            ans += dep * pb;
            return;
        }

        // Number of children, excluding parent.
        int children = (u == 1 ? size : size - 1);

        double npb = 1.0 / children;

        for (int v : tree[u]) {
            if (v == p) continue;

            dfs(v, u, pb * npb, dep + 1);
        }
    };

    dfs(1, 0, 1.0, 0);

    cout << fixed << setprecision(10) << ans << '\n';
}



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        // coordinator();
        // matching_tree();
        // diameter();
        // tree_dist_one();
        // tree_dist_two();
        // comapany_query_one();
        // company_query_two();
        // distance_queries();
        // counting_path();
        // subtree_queries();
        // path_query();
        //  distinct_color();
        // tree_painting();
        // party();
        expected_length_journey();
    }

    return 0;
}