#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6*4;
int n, q;
int a[maxn];
long long st[maxn];
long long sum[maxn];

void build(int id, int l, int r){
    if(l == r){
        sum[id] = a[l];
        return;
    }

    int m = (l+r)/2;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    
    sum[id] = sum[id*2] + sum[id*2+1];
}

long long get_sum(int id, int l, int r, int u, int v){
    if(r < u || l > v) return 0;
    if(u <= l && r <= v) return sum[id];

    int mid = (l+r)/2;
    long long sum1 = get_sum(id*2, l, mid, u, v);
    long long sum2 = get_sum(id*2+1, mid+1, r, u, v);

    return sum1+sum2;
}

void update(int id, int l, int r, int val, int pos){
    if(pos < l || pos > r) return;
    if(l == r){
        sum[id] = val;
        a[l] = val;
        return;
    }

    int m = (l+r)/2;
    update(id*2, l, m, val, pos);
    update(id*2+1, m+1, r, val, pos);

    sum[id] = sum[id*2] + sum[id*2+1];
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    while(q > 0){
        int a, b, c;
        cin >> a >> b >> c;
        q--;
        if(a == 1){
            update(1, 1, n, c, b);
        }
        else if(a == 2){
            int ans = get_sum(1, 1, n, b, c);
            cout << ans << endl;
        }
    }
    return 0;
}