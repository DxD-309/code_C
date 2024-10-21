#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1000];
int color[1000];
int in[1000];

bool dfs(int u){
    color[u] = 1;
    for(auto v : adj[u]){
        if(color[v] == 0){
            color[v] = 1;
            if(dfs(v)) return true;
        }
        else if(color[v] == 1){
            return true;
        }
    }
    color[u] = 2;
    return false;
}

bool bfs(int u){
    queue<int> q;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        ++cnt;
        for(auto x : adj[v]){
            in[x]--;
            if(in[x] == 0) q.push(x);
        }
    }
    return cnt != n;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if(dfs(i)){
                cout << "ok" << endl;
                return 0;
            }
        }
    }
    cout << "ko" << endl;
    return 0;
}