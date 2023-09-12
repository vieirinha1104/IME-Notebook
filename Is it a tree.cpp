#include <bits/stdc++.h>
#define N 1000000

using namespace std;

int n,m;
vector<int> adj[N],vis(N);
bool check;

void cyclic(int curl,int prev){ //basicamente um dfs modificado
    vis[curl]=1;
    for(auto e : adj[curl]){
        if(!vis[e]) cyclic(e,curl);
        else if(vis[e] and e!=prev) check=true;
        //obs, se voce trocar esse 'else if' por 'if' o codigo nao vai funcionar

    }
}
//Obs, nem precisaria verificar se o grafo era ciclico, basta verificar conexidade e se n-1=m
int main(){
    check=false;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cyclic(1,0);
    if(check){
        cout <<"NO\n"; return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cout << "NO\n"; return 0;
            }
        }
        cout << "YES\n"; return 0;
    }
}