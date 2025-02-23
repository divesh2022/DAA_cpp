#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int binary_search(const vector<int>& lst, int start, int stop, int key) {
    if (start > stop) {
        return -1;
    } else {
        int mid = (start + stop) / 2;
        if (key == lst[mid]) {
            return mid;
        } else if (key < lst[mid]) {
            return binary_search(lst, start, mid - 1, key);
        } else {
            return binary_search(lst, mid + 1, stop, key);
        }
    }
}

void sort(vector<int>& lst) {
    for (size_t i = 0; i < lst.size(); i++) {
        for (size_t j = 0; j < lst.size() - 1; j++) {
            if (lst[j] > lst[j + 1]) {
                int temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
            }
        }
    }
}

void main_program() {
    string input;
    cout << "Enter the list of numbers separated by hyphens: ";
    cin >> input;
    stringstream ss(input);
    vector<int> lst;
    while (ss.good()) {
        string substr;
        getline(ss, substr, '-');
        lst.push_back(stoi(substr));
    }

    cout << "Unsorted list is [ ";
    for (const auto& num : lst) {
        cout << num << " ";
    }
    cout << "]" << endl;

    sort(lst);
    cout << "Sorted list is [ ";
    for (const auto& num : lst) {
        cout << num << " ";
    }
    cout << "]" << endl;

    int key;
    cout << "Enter value to find: ";
    cin >> key;
    int res = binary_search(lst, 0, lst.size() - 1, key);
    if (res != -1) {
        cout << "Element found at index " << res << endl;
    } else {
        cout << "Element not found" << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of test cases: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        main_program();
    }
    return 0;
}
