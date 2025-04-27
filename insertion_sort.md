# Insertion Sort Implementation

This repository contains an implementation of the **Insertion Sort** algorithm in C++ with support for sorting arrays of multiple data types (`int`, `float`, `double`, `char`, and `string`) using templates.

## Algorithm

Insertion Sort is a simple and efficient algorithm for small datasets. It builds the sorted array one element at a time by comparing and shifting elements.

### Algorithm Steps (in Code Format)
```cpp
for (int i = 1; i < size; ++i) {
    T key = A[i];
    int j = i - 1;
    // Shift elements of A[0..i-1] that are greater than key
    while (j >= 0 && key < A[j]) {
        A[j + 1] = A[j];
        j = j - 1;
    }
    A[j + 1] = key; // Place key in its correct position
}
