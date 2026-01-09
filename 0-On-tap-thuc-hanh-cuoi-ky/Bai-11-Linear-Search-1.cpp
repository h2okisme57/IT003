// Ý tưởng: Duyệt mảng từ đầu để tìm x, nếu tìm thấy thì in vị trí và số lần duyệt.
// Nếu không tìm thấy thì in -1 và kết thúc chương trình.

#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int pos1 = -1; 
    int count1 = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        count1++;
        if (a[i] == x) {
            pos1 = i;
            found = true;
            break;
    }
}
    if (!found) {
        cout << -1 << endl;
        return;
    }
    cout << pos1 << endl;
    cout << count1 << endl;
    int pos2 = -1;
    int count2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        count2++; 
        if (a[i] == x) {
            pos2 = (n - 1) - i;
            break; 
        }
    }
    cout << pos2 << endl;
    cout << count2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}