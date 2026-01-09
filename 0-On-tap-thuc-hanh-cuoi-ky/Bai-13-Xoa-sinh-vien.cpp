#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Nhap(char a[]) {
    cin.getline(a, 100);
}

void Nhap(SinhVien A[], int& n) {
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> A[i].MASV;
        cin.ignore();
        cin.getline(A[i].HoTen, 100);
        cin >> A[i].NgaySinh;
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan;
        cin >> A[i].DiemLy;
        cin >> A[i].DiemHoa;
    }
}

void XoaTheoHoTen(SinhVien A[], int& n, char a[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(A[i].HoTen, a) == 0) {
            for (int j = i; j < n - 1; j++) {
                A[j] = A[j + 1];
            }
            n--;
            i--;
        }
    }
}

void Xuat(SinhVien A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i].DTB = (A[i].DiemHoa + A[i].DiemLy + A[i].DiemToan) / 3;
        cout << A[i].MASV << "\t" << A[i].HoTen << "\t" << A[i].NgaySinh << "\t" << A[i].GioiTinh << "\t" << A[i].DiemToan << "\t" << A[i].DiemLy << "\t" << A[i].DiemHoa << "\t" << setprecision(3) << A[i].DTB << "\n";
    }
}


int main() {
    SinhVien A[MAXN];
    char hoTenCanXoa[100];
    int n;
    Nhap(hoTenCanXoa);
    Nhap(A, n);
    XoaTheoHoTen(A, n, hoTenCanXoa);
    Xuat(A, n);
    return 0;
}

