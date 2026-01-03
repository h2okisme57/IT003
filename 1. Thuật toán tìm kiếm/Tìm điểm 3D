#include <iostream>
#include <vector>
using namespace std;

struct Diem {
    double x, y, z;
};

int main() {
    int n;
    cin >> n;

    vector<Diem> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }
    int m;
    cin >> m;
    vector<Diem> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i].x >> B[i].y >> B[i].z;
    }
    for (int j=0; j<m; j++)
    {
        int t=0;
        for (int i = 0; i < n; i++) {
            if (A[i].x == B[j].x && A[i].y == B[j].y && A[i].z == B[j].z) {
                cout << i << endl;
                t++;
                i==n;
            }  
        }
        if (t==0) cout << "KHONG\n";
    }
    return 0;
}
