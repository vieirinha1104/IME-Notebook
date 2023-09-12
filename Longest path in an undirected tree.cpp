#include <bits/stdc++.h>
#define N 1000000


using namespace std;

int n;
vector<int> adj[N],vis(N),heigh(N),leaf;

void dfs(int curl){
    if(adj[curl].size()==1){
        leaf.push_back(curl);
    }
    vis[curl]=1;
    for(auto e : adj[curl]){
        if(!vis[e]){
            height[e]=height[curl]+1;
            dfs(e);
        }
    }
}


int main(){
    height[1]=1;
    cin >> n;
    for(int i=1;i<=n-1;i++){
        int a,b; cin >> a >> b;
        if(a==b) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1); int max=height[leaf[0]]; int node=leaf[0];
    for(int i=0;i<leaf.size();i++){
        if(height[leaf[i]]>max){
            max=height[leaf[i]];
            node=leaf[i];
        }
    }
    for(int i=0;i<N;i++){
        height[i]=0; vis[i]=0;
    }
    height[node]=1; dfs(node); sort(height.begin(),height.end());
    cout << height[N-1]-1 << "\n";
}