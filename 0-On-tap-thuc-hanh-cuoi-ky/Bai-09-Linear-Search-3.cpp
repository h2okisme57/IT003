// Ý tưởng: Sử dụng một mảng boolean để đánh dấu các số đã xuất hiện.
// MEX hiện tại được cập nhật bằng cách tăng dần từ 0 đến khi tìm thấy số chưa xuất hiện.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VAL = 200001;
bool xuathien[MAX_VAL]; // Mảng đánh dấu các số đã xuất hiện

void solve() {
    int n;
    cin >> n;
    int mex_0 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < MAX_VAL) {
            xuathien[x] = true; // Đánh dấu số x đã xuất hiện
        }
        while (xuathien[mex_0]) {
            mex_0++; // Tăng MEX cho đến khi tìm thấy số chưa xuất hiện
        }
        cout << mex_0 << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}