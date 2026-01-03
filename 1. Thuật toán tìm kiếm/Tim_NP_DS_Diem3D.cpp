#include <bits/stdc++.h>
using namespace std;

struct Diem {
    double x, y, z;
};

double dodai(double a, double b, double c) {
    return sqrt(a*a + b*b + c*c);
}

int main() {
    int n;
    cin >> n;

    vector<Diem> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }

    double b, e;
    cin >> b >> e;

    vector<Diem> Ketqua;
    for (int i = 0; i < n; i++) {
        double k = dodai(A[i].x, A[i].y, A[i].z);
        if (b <= k && k <= e) {
            Ketqua.push_back(A[i]);
        }
    }

    if (Ketqua.empty()) {
        cout << "KHONG\n";
    } else {
        for (int i = 0; i < (int)Ketqua.size(); i++) {
            cout << Ketqua[i].x << " " << Ketqua[i].y << " " << Ketqua[i].z << "\n";
        }
    }
    return 0;
}
