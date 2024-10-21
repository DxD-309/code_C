// ĐIỀU KIỆN:

// *ĐỒ THỊ VÔ HƯỚNG:
// - Các đỉnh có bậc khác 0 liên thông với nhau
// - Tất cả đỉnh của đồ thị có bậc chẵn

// *ĐỒ THỊ CÓ HƯỚNG
// - Cách đỉnh có bậc khác 0 của đồ thị thuộc một thành phần liên thông
// - Mọi đỉnh của đồ thị có bán bậc ra bằng bán bậc vào

#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> adj[1001];
int degree[1001];
vector<int> ec;

void euler_cycle(int u){
    stack<int> st;
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        if(adj[v].size() != 0){
            int x = *adj[v].begin();
            st.push(x);
            adj[x].erase(v);
            adj[v].erase(x);
            degree[x]--;
            degree[v]--;
        }
        else{
            st.pop();
            ec.push_back(v);
        }
    }
    reverse(ec.begin(), ec.end());
    for(auto k : ec){
        cout << k << " ";
    }
    cout << endl;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
    euler_cycle(1);
    return 0;
}