#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;
const int maxn = 1e5+7;

int n, q;
int a[maxn];
long long st[maxn*4];
long long lazy[maxn*4];

void build(int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }

    int m = (l+r)/2;
    build(id*2, l, m);
    build(id*2+1, m+1, r);

    st[id] = max(st[id*2], st[id*2+1]);
}

void fix(int id, int l, int r){
    if(!lazy[id]) return;
    st[id] += lazy[id];

    if(l != r){
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    fix(id, l, r);
    if(l > v || r < u) return;
    if(u <= l && r <= v){
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int m = (l+r)/2;
    update(id*2, l, m, u, v, val);
    update(id*2+1, m+1, r, u, v, val);

    st[id] = max(st[id*2], st[id*2+1]);
}

long long get(int id, int l, int r, int u, int v){
    fix(id, l, r);
    if(l > v || r < u) return -inf;
    if(u <= l && r <= v){
        return st[id];
    } 

    int m = (l+r)/2;
    long long get1 = get(id*2, l, m, u, v);
    long long get2 = get(id*2+1, m+1, r, u, v);
    return max(get1, get2);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);

    cin >> q;
    while(q--){
        int type, l, r, val;
        cin >> type >> l >> r;
        if(type == 1){
            cin >> val;
            update(1, 1, n, l, r, val);
        }
        else cout << get(1, 1, n, l, r) << endl;
    }
}