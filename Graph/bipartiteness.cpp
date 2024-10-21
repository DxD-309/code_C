#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
int color[1000];
int n, m;

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
}

bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto x : adj[v]){
            if(color[x] == -1){
                color[x] = 1 - color[v];
                q.push(x);
            }
            else if(color[x] == color[v]) return false;
        }
    }
    return true;
}

bool dfs(int u, int par){
    color[u] = 1-color[par];
    for(auto v : adj[u]){
        if(color[v] == -1){
            if(!dfs(v, u)) return false;
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
}

int main(){
    inp();
    bool ok = true;
    color[0] = 0;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!dfs(i, 0)){
                ok = false;
                break;
            }
        }
    }
    if(ok) cout << "ok" << endl;
    else cout << "cc" << endl;
    return 0;
}