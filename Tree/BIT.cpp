#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 7;
vector<long long> b1, b2;
long long n, q;
long long a[maxn];

void update(vector<long long>& bit, long long u, long long val) {
    long long ind = u;
    while (ind <= n) {
        bit[ind] += val;
        ind += ind & (-ind);
    }
}

void updateOnRange(long long l, long long r, long long val) {
    update(b1, l, (n - l + 1) * val);
    update(b1, r + 1, -(n - r) * val);
    update(b2, l, val);
    update(b2, r + 1, -val);
}

long long getSum(vector<long long>& bit, long long u) {
    long long ind = u;
    long long sum = 0;
    while (ind > 0) {
        sum += bit[ind];
        ind -= ind & (-ind);
    }
    return sum;
}

long long prefixSum(long long u) {
    return getSum(b1, u) - getSum(b2, u) * (n - u);
}

long long rangeSum(long long l, long long r) {
    return prefixSum(r) - prefixSum(l - 1);
}

int main() {
    cin >> n >> q;
    b1.resize(n + 1);
    b2.resize(n + 1);

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        updateOnRange(i, i, a[i]);
    }

    while (q--) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long l, r, val;
            cin >> l >> r >> val;
            updateOnRange(l, r, val);
        } else {
            long long k;
            cin >> k;
            cout << rangeSum(k, k) << endl;
        }
    }

    return 0;
}