#include<bits/stdc++.h>
using namespace std;


int n, m;
vector<int> adj[1000];
bool visited[1000];
vector<int> topo;
int in[1000];

void inp(){
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
}

//BFS
void kahn(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(auto v : adj[u]){
            in[v]--;
            if(in[v] == 0){
                q.push(v);
            }
        }
    }
}

//DFS
// void dfs(int u){
//     visited[u] = true;
//     for(auto v : adj[u]){
//         if(!visited[v]) dfs(v);
//     } 
//     topo.push_back(u);
// }

int main(){
    inp();
    kahn();
    reverse(topo.begin(), topo.end());
    for(auto it : topo){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}