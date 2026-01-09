#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    const int MAX_VAL = 100005;
    vector<int> exist(MAX_VAL, 0); 

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val < MAX_VAL) {
            exist[val] = 1;
        }
    }
    int mex = 0;
    while (exist[mex] == 1) {
        mex++;
    }

    cout << mex << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}