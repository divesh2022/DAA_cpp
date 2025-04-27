#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ArrayHandler {
private:
    vector<int> originalArray;
    vector<int> clonedArray;

public:
    // Constructor to initialize the array
    ArrayHandler(const vector<int>& array) {
        originalArray = array;
        clonedArray = array; // Clone the original array
    }

    // Function to perform insertion sort on the cloned array
    bool performSort() {
        try {
            for (size_t i = 1; i < clonedArray.size(); ++i) {
                int key = clonedArray[i];
                int j = i - 1;
                while (j >= 0 && key < clonedArray[j]) {
                    clonedArray[j + 1] = clonedArray[j];
                    --j;
                }
                clonedArray[j + 1] = key;
            }
            // If sorting is successful, replace the original array
            originalArray = clonedArray;
            return true;
        } catch (...) {
            // If sorting fails, return error code
            return false;
        }
    }

    // Function to show the array
    void showArray() const {
        for (size_t i = 0; i < originalArray.size(); ++i) {
            cout << "A[" << i << "] = " << originalArray[i] << endl;
        }
    }

    // Function to show the error if sorting fails
    void handleError() const {
        cout << "Error Code: 106 - Sorting failed. Original array retained." << endl;
    }
};

int main() {
    char ch = 'y';
    while (ch == 'y') {
        cout << "Enter the size of the array: ";
        int size;
        cin >> size;

        vector<int> array(size);
        for (int i = 0; i < size; ++i) {
            cout << "Enter the element at index " << i << ": ";
            cin >> array[i];
        }

        cout << "Before sorting:" << endl;
        ArrayHandler handler(array);
        handler.showArray();

        if (handler.performSort()) {
            cout << "After sorting:" << endl;
            handler.showArray();
        } else {
            handler.handleError();
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
        if (ch != 'y' && ch != 'n') {
            cout << "Invalid input. Exiting..." << endl;
            break;
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}
