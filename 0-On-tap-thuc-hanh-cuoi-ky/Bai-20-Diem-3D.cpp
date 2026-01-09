// Ý tưởng: Sử dụng thuật toán Merge Sort tùy chỉnh để sắp xếp các điểm 3D theo thứ tự yêu cầu

#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y, z;
};

vector<Point> tempArr; // Mảng tạm để hỗ trợ quá trình sắp xếp

bool kiemtra(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x; 
    if (a.y != b.y) return a.y > b.y; 
    return a.z < b.z;
}

void Gop(vector<Point> &arr, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (kiemtra(arr[i], arr[j])) {
            tempArr[k++] = arr[i++];
        } else {
            tempArr[k++] = arr[j++];
        }
    }
    while (i <= m) tempArr[k++] = arr[i++];
    while (j <= r) tempArr[k++] = arr[j++];

    for (int idx = l; idx <= r; ++idx) {
        arr[idx] = tempArr[idx];
    }
}

void chiadetri(vector<Point> &arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    chiadetri(arr, l, m);
    chiadetri(arr, m + 1, r);
    Gop(arr, l, m, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <Point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    tempArr.resize(n);
    chiadetri(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
    }
    return 0;
}