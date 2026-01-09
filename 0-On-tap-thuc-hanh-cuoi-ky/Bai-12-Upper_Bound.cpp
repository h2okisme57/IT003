// Ý tưởng: Sắp xếp mảng sử dụng thuật toán Merge Sort và tìm phần tử nhỏ nhất lớn hơn x sử dụng tìm kiếm nhị phân.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upper_bound(int n, vector<int> &a, int x) {
    int trai = 0;
    int phai = n - 1;
    int ket_qua = -1;

    while (trai <= phai) {
        int giua = trai + (phai - trai) / 2;
        if (a[giua] > x) {
            ket_qua = a[giua];
            phai = giua - 1;
        } else {
            trai = giua + 1; 
        }
    }
    return ket_qua;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << upper_bound(n, a, x) << "\n";
    }
    return 0;
}