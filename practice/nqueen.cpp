#include <bits/stdc++.h>
using namespace std;

int n, x[100], cot[100], d1[100], d2[100];
int a[100][100];

void in(){
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++){
        a[i][x[i]] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void queen(int i){
    for(int j = 1; j <= n; j++){
        if(cot[j] == 1 && d1[i - j + n] == 1 && d2[i + j - 1] == 1){
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            x[i] = j;
            if(i == n){
                in();
            }
            else{
                queen(i+1);
            }
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i <= 100; i++){
        cot[i] = d1[i] = d2[i] = 1;
    }
    queen(1);
    return 0;
}