#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1000];
bool visited[1000];
int parent[1000];
int st, en;

bool dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            visited[v] = true;
            if(dfs(v)) return true;
        }
        else if(v != parent[u]){
            st = v;
            en = u;
            return true;
        }
    }
    return false;
}


bool bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        for(auto i : adj[v]){
            if(!visited[i]){
                parent[i] = v;
                visited[i] = true;
                q.push(i);
            }
            else if(i != parent[v]){ 
                st = i;
                en = v;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(bfs(i)){
                cout << "ok" << endl;
                vector<int> path;
                path.push_back(st);
                while(en != st){
                    path.push_back(en);
                    en = parent[en];
                }
                path.push_back(st);
                reverse(path.begin(), path.end());
                for(auto x : path){
                    cout << x << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "ko" << endl;
    return 0;
}