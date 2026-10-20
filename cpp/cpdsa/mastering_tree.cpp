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
        company_query_two();
    }

    return 0;
}