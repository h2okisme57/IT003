#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int min = a [1] - a[0];
    for (int i =1; i< n - 1; i++)
    {
        int t = a [i+1] - a[i];
        if (t < min) min = t;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i+1] - a[i] == min)
        {
            cout << a[i] << " " << a[i+1] << " ";
        }
    }
    return 0;
}
