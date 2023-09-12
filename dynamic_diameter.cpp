#include <bits/stdc++.h>
#define N 1000000


using namespace std;

int n;
vector<int> adj[N],vis(N),dis(N),ans(N);
int u,v; //u:Extremo do primeiro dfs e v:Extremo do segundo dfs
int e1,e2; // e1: excentricidade do no usado no primeiro dfs e2:excentricidade do no usado no segundo dfs

void dfs(int curl,int & e,int & u){
    vis[curl]=1;
    if(dis[curl]>e){
        e=dis[curl]; u=curl;
    }
    for(auto x : adj[curl]){
        if(!vis[x]){
            dis[x]=dis[curl]+1;
            dfs(x,e,u);
        }
    }
}
int main(){
    e1=0; e2=0;
    cin >> n;
    for(int i=1;i<=(n-1);i++){
        int a,b; cin >> a >> b;
        if(a==b) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,e1,u); //DFS no no '1' para achar u, obs:e1 eh inutil
    for(int i=0;i<N;i++){
        vis[i]=0; dis[i]=0;
    }
    dfs(u,e2,v); //DFS no no 'u' para achar e2 e v, obs:e2 eh o diametro
    //alem disso: apos esse dfs, o vector for att para dis[i]=dis(i,u)
    for(int i=1;i<=n;i++){
        ans[i]=(e2+(e2==dis[i]));
    }
    for(int i=0;i<N;i++){
        vis[i]=0; dis[i]=0;
    }
    dfs(v,e1,u); //DFS no no'v' para achar dis[i]=dis(i,v)
    for(int i=1;i<=n;i++){
        ans[i]=max( ans[i] , e2+(e2==dis[i]) );
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }
   
}

