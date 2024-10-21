#include <bits/stdc++.h>
using namespace std;

string s, t;
const long long MOD = 1e9 + 7;
const int base = 31;
long long p[1000000];
long long f[1000000];
long long hashT;

long long getHash(int l, int r){
    return (f[r] - f[l-1]*p[r-l+1] + MOD*MOD)%MOD;
}

int main(){
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    s = " " + s;
    t = " " + t;    

    p[0] = 1;
    for(int i = 1; i <= n; i++){
        p[i] = (p[i-1]*base)%MOD;
    }

    hashT = 0;
    for(int i = 1; i <= m; i++){
        hashT = (hashT*base + t[i] - 'a' + 1)%MOD;
    }

    for(int i = 1; i <= n; i++){
        f[i] = (f[i-1]*base + s[i] - 'a' + 1)%MOD;
    }

    for(int i = 1; i <= n-m+1; i++){
        if(hashT == getHash(i, i+m-1)){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}