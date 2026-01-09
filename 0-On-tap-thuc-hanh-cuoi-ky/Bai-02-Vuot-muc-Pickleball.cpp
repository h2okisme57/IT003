// Ý tưởng: Sử dụng mảng đếm để theo dõi tần suất xuất hiện của các giá trị trong cửa sổ kích thước d

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    const int MAX = 200; // giá trị lớn nhất của phần tử trong mảng a
    vector <int> dem (MAX, 0); // mảng đếm tần suất xuất hiện
    for (int i = 0; i < d; i++)
        dem[a[i]]++; // đếm số lần xuất hiện của các giá trị trong khoảng đầu tiên
    int count = 0;
    for (int i = d; i < n; i++) {
        int acc = 0; // biến tích lũy để tìm median
        int m1 = -1, m2 = -1; // median thứ nhất và thứ hai
        for (int v = 0; v < MAX; v++) {
            acc += dem[v]; // cập nhật biến tích lũy
            if (m1 == -1 && acc >= (d + 1) / 2) // tìm median thứ nhất
                m1 = v;
            if (acc >= (d + 2) / 2) {
                m2 = v; 
                break;
            }
        }
        // tính median nhân đôi để tránh số thực
        int twiceMedian;
        if (d % 2 == 1)
            twiceMedian = 2 * m2;
        else
            twiceMedian = m1 + m2;
        if (a[i] >= twiceMedian)
            count++; 
        dem[a[i - d]]--;
        dem[a[i]]++;
    }
    cout << count;
    return 0;
}
