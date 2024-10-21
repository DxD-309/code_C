//MINIMUM SPANNING TREE
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1000];
bool used[1000];
int parent[1000], d[1000];

struct edge{
    int u, v;
    int w;
};

//PRIM
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        d[i] = INT_MAX;
    }
}

void prim(int u){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, u});
    vector<edge> mst;
    int res = 0;
    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int dinh = it.second, weight = it.first;

        if(used[dinh]) continue;
        res += weight;
        used[dinh] = true;
        if(u != dinh){
            mst.push_back({parent[dinh], dinh, weight});
        }
        for(auto tmp : adj[dinh]){
            int x = tmp.first;
            int y = tmp.second;
            if(!used[x] && y < d[x]){
                d[x] = y;
                parent[x] = dinh;
                q.push({y, x});
            }
        }
    }
    cout << res << endl;
    for(auto it : mst){
        cout << it.u << " " << it.v << " " << it.w << endl;
    }
}


//KRUSKAL
// vector<edge> canh;
// int parent[100];
// int sz[100];

// void make_set(){
//     for(int i = 1; i <= n; i++){
//         parent[i] = i;
//         sz[i] = 1;
//     }
// }

// int find_set(int v){
//     if(v == parent[v]) return v;
//     else return parent[v] = find_set(parent[v]);
// }

// bool union_find(int u, int v){
//     u = find_set(u);
//     v = find_set(v);
//     if(u == v) return false;
//     if(sz[u] < sz[v]) swap(u, v);
//     parent[v] = u;
//     sz[u] += sz[v];
//     return true;
// }

// void inp(){
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         edge e;
//         e.u = u;
//         e.v = v;
//         e.w = w;
//         canh.push_back(e);
//     }
// }

// bool cmp(edge a, edge b){
//     return a.w < b.w;
// }

// void kruskal(){
//     vector<edge> mst;
//     int d = 0;
//     sort(canh.begin(), canh.end(), cmp);
//     for(int i = 0; i < m; i++){
//         if(mst.size() == n-1) break;
//         edge e = canh[i];
//         if(union_find(e.u, e.v)){
//             mst.push_back(e);
//             d += e.w;
//         }
//     }
//     if(mst.size() != n-1){
//         cout << "ko" << endl;
//     }
//     else{
//         cout << d << endl;
//         for(int i = 0; i < mst.size(); i++){
//             auto e = mst[i];
//             cout << e.u << " " << e.v << " " << e.w;
//             cout << endl;
//         }
//     }
// }

int main(){
    inp();
    prim(1);
}