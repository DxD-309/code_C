#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
bool visited[1000];
int n, m;

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void khop(){
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            tplt++;
            dfs(i);
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        int dem = 0;
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        for(int j = 1; j <= n; j++){
            if(!visited[j]){
                dem++;
                dfs(j);
            }
        }
        if(dem > tplt){
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    inp();
    khop();
    return 0;
}