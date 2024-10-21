#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
bool visited[1000];
int n, m;
vector<pair<int, int>> dscanh;

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dscanh.push_back({x, y});
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

void dfs2(int u, int s, int t){
    visited[u] = true;
    for(auto v : adj[u]){
        if((u == t && v == s) || (u == s && v == t)) continue;
        if(!visited[v]) dfs2(v, s, t);
    }
}

void cau(){
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            tplt++;
            dfs(i);
        }
    }
    int ans = 0;
    for(auto it : dscanh){
        int x = it.first, y = it.second;
        memset(visited, false, sizeof(visited));
        int dem = 0;
        for(int j = 1; j <= n; j++){
            if(!visited[j]){
                dem++;
                dfs2(j, x, y);
            }
        }
        if(dem > tplt) ans++;
    }
    cout << ans << endl;
}

int main(){
    inp();
    cau();
    return 0;
}