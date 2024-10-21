#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<int> ans;

int main() {
    cin >> a >> b;
    vector<int> lps(b.length(), 0);
    unsigned int i = 1;
    int prevlps = 0;
    while (i < b.length()) { 
        if (b[i] == b[prevlps]) {
            lps[i] = prevlps + 1;
            prevlps++;
            i++;
        } else if (prevlps == 0) {
            lps[i] = 0;
            i++;
        } else {
            prevlps = lps[prevlps - 1];
        }
    }
    unsigned int j = 0;
    for (unsigned int i = 0; i < a.length(); i++) {
        while (j > 0 && a[i] != b[j]) {
            j = lps[j - 1];
        }
        if (a[i] == b[j]) {
            j++;
        }
        if (j == b.length()) {
            ans.push_back(i - b.length() + 2);
        }
    }
    for (unsigned int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}