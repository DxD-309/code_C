#include <bits/stdc++.h>
using namespace std;

int p[50001];

string prepo(string s) {
    string c = "#";
    int n = s.length();
    for (int i = 0; i < n; i++) {
        c += s[i];
        c += '#';
    }
    return c;
}

string postpro(string c) {
    string ans = "";
    int n = c.length();
    for (int i = 0; i < n; i++) {
        if (c[i] == '#')
            continue;
        else
            ans += c[i];
    }
    return ans;
}

string manacher(string s) {
    string ans = "";
    string c = prepo(s);
    int center = 0, right = 0;
    int n = c.length();
    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;
        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        } else {
            p[i] = 0;
        }

        while (i - 1 - p[i] >= 0 && i + 1 + p[i] < n && c[i - 1 - p[i]] == c[i + 1 + p[i]]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    int maxlen = 0;
    int centerind = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] > maxlen) {
            maxlen = p[i];
            centerind = i;
        }
    }

    ans = c.substr(centerind - maxlen, maxlen * 2 + 1);
    return ans;
}

int main() {
    int n;
    cin >> n;
    char a[50001];
    string s = "";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        if (i != n - 1) {
            s += "";
        }
    }
    string ans = postpro(manacher(s));
    cout << ans.length() << endl;
    return 0;
}