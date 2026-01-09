#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Sanpham {
    string id;
    int count;
};

bool check_smaller_id(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

bool check_priority(const Sanpham& a, const Sanpham& b) {
    if (a.count != b.count) {
        return a.count > b.count; 
    }
    return check_smaller_id(a.id, b.id);
}

void combine_strings(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        
        if (check_smaller_id(L[i], R[j]) || L[i] == R[j]) {
            arr[k] = L[i]; i++;
        } else {
            arr[k] = R[j]; j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void organize_raw_input(vector<string>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    organize_raw_input(arr, left, mid);
    organize_raw_input(arr, mid + 1, right);
    combine_strings(arr, left, mid, right);
}

void combine_items(vector<Sanpham>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Sanpham> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (check_priority(L[i], R[j])) {
            arr[k] = L[i]; i++;
        } else {
            arr[k] = R[j]; j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void organize_final_output(vector<Sanpham>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    organize_final_output(arr, left, mid);
    organize_final_output(arr, mid + 1, right);
    combine_items(arr, left, mid, right);
}


void run_process() {
    int N;
    if (!(cin >> N)) return;
    vector<string> raw_codes(N);
    for (int i = 0; i < N; i++) {
        cin >> raw_codes[i];
    }

    if (N == 0) return;
    organize_raw_input(raw_codes, 0, N - 1);
    vector<Sanpham> result_list;
    int current_freq = 1;
    
    for (int i = 1; i < N; i++) {
        if (raw_codes[i] == raw_codes[i - 1]) {
            current_freq++;
        } else {

            Sanpham item;
            item.id = raw_codes[i - 1];
            item.count = current_freq;
            result_list.push_back(item);
            current_freq = 1;
        }
    }

    Sanpham last_item;
    last_item.id = raw_codes[N - 1];
    last_item.count = current_freq;
    result_list.push_back(last_item);

    organize_final_output(result_list, 0, result_list.size() - 1);

    for (int i = 0; i < result_list.size(); i++) {
        cout << result_list[i].id << " " << result_list[i].count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run_process();
    return 0;
}