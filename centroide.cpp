#include <bits/stdc++.h>
#define N 1000000


using namespace std;

int n,sz[N];
vector<int> adj[N],vis(N),cent;

void dfs(int curl){
    bool ok=true;
    sz[curl]=1;
    for(auto e : adj[curl]){
        if(!vis[e]){
            vis[e]=1;dfs(e);
            sz[curl]+=sz[e];
            if(2*sz[e]>n) ok=false;
        }
    }
    if( ok and (2*(n-sz[curl])<=n) ) cent.push_back(curl);
}
int main(){
    cin >> n;
    for(int i=1;i<=(n-1);i++){
        int a,b; cin >> a >> b;
        if(a==b) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1); 
    for(auto e : cent){
        cout << e << "\n";
    }
   
}

