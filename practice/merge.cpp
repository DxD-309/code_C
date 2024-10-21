#include <iostream>
using namespace std;

#define maxn 10000

int a[maxn];

void merge(int data[], int l, int m, int r) {
    int size = r - l + 1;
    int i = l, j = m + 1;
    int curr = 0;
    while (i <= m && j <= r) {
        if (data[i] < data[j]) {
            a[curr++] = data[i++];
        } else {
            a[curr++] = data[j++];
        }
    }

    while (i <= m) {
        a[curr++] = data[i++];
    }

    while (j <= r) {
        a[curr++] = data[j++];
    }

    for (int k = 0; k < size; ++k) {
        data[l + k] = a[k];
    }
}

void mergeSort(int data[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(data, l, m);
        mergeSort(data, m + 1, r);
        merge(data, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[maxn];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}