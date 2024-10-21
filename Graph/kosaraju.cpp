#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1000];
vector<int> r_adj[1000];
bool used[1000];
stack<int> s;

void dfs1(int u){
    used[u] = true;
    for(auto v : adj[u]){
        if(!used[v]){
            dfs1(v);
        }
    }
    s.push(u);
    cout << u << " ";
}

void dfs2(int u){
    used[u] = true;
    cout << u << " ";
    for(auto v : r_adj[u]){
        if(!used[v]){
            dfs2(v);
        }
    }
}

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}

void scc(){
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            dfs1(i);
        }
    }
    cout << endl;
    memset(used, false, sizeof(used));
    while(!s.empty()){
        auto u = s.top();
        s.pop();
        if(!used[u]){
            dfs2(u);
            cout << endl;
        }
    }
}

int main(){
    inp();
    scc();
}