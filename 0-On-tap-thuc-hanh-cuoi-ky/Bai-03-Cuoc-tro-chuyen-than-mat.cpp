#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int countMinSwaps(vector<int> arr, bool (*compare)(int, int)) {
    int n = arr.size();
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = {arr[i], i};
    }

    sort(nums.begin(), nums.end(), [compare](const pair<int, int>& a, const pair<int, int>& b) {
        return compare(a.first, b.first);
    });

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || nums[i].second == i) {
            continue;
        }
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = nums[j].second;
            cycle_size++;
        }

        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }
    return swaps;
}

bool ascending(int a, int b) { return a < b; }
bool descending(int a, int b) { return a > b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        int swapTang = countMinSwaps(a, ascending);
        int swapGiam = countMinSwaps(a, descending);
        cout << min(swapTang, swapGiam);
    }
    return 0;
}