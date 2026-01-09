// Ý tưởng: Chia mảng theo Merge Sort và in mảng sau mỗi lần gộp

#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int> &arr, int l, int r) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i > 0) cout << " ";
        if (i == l) cout << "[ ";
        cout << arr[i];
        if (i == r) cout << " ]";
    }
    cout << "\n";
}

void merge(vector<int> &arr, int l, int m, int r) { // gộp hai mảng đã sắp xếp
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    display(arr, l, r);
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    mergeSort(a, 0, n - 1);
    return 0;
}