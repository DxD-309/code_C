#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[10000];
int par[10000];
int n, m, s, t;

void inp(){
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
}

void dijkstra(int s, int t){
    vector<int> d(n+1, 1e9);
    d[s] = 0;
    par[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});

    while(!q.empty()){
        auto top = q.top(); q.pop();
        int u = top.second;
        int kc = top.first;

        if(kc > d[u]) continue;
        for(auto x : adj[u]){
            int v = x.first;
            int w = x.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
                par[v] = u;
            }
        }
    }

    cout << d[t] << endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        t = par[t];
        if(t == s) break;
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    for(auto it : path){
        cout << it << " ";
    }
}

int main(){
    inp();
    dijkstra(s, t);
    return 0;
}