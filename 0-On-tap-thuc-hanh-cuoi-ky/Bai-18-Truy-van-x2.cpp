#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (cin >> N >> Q) {
        vector<pii> a(N);
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            a[i] = {val, i + 1};
        }
        sort(a.begin(), a.end());

        string s;
        while (Q--) {
            int type, y;
            cin >> s >> type >> y;

            if (type == 1) {
                auto it = lower_bound(a.begin(), a.end(), make_pair(y, -2000000000));
                if (it != a.end() && it->first == y) {
                    cout << it->second << "\n";
                } else {
                    cout << "-1\n";
                }
            } else {
                auto it = upper_bound(a.begin(), a.end(), make_pair(y, 2000000000));
                if (it == a.begin()) {
                    cout << "-1\n";
                } else {
                    it--;
                    if (it->first == y) {
                        cout << it->second << "\n";
                    } else {
                        cout << "-1\n";
                    }
                }
            }
        }
    }
    return 0;
}