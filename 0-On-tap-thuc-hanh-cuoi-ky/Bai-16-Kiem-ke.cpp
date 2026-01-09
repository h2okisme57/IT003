#include <iostream>
#include <vector>
#include <string>

using namespace std;

void combine_arrays(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void organize_data(vector<string>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    organize_data(arr, left, mid);
    organize_data(arr, mid + 1, right);

    combine_arrays(arr, left, mid, right);
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return;
    
    if (N == 0) {
        cout << 0;
        return;
    }
    vector<string> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i];
    }
    organize_data(items, 0, N - 1);
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (items[i] != items[i - 1]) {
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    solve();
    return 0;
}