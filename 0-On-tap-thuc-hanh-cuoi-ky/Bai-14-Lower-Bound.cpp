#include <bits/stdc++.h>
using namespace std;

long long a[100000];

void qs(int l, int r) {
    int i = l, j = r;
    long long pivot = a[(l + r) >> 1];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) qs(l, j);
    if (i < r) qs(i, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    qs(0, N - 1);

    while (Q--) {
        long long x;
        cin >> x;

        int l = 0, r = N - 1;
        int pos = -1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= x) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (pos == -1) cout << -1 << '\n';
        else cout << a[pos] << '\n';
    }

    return 0;
}