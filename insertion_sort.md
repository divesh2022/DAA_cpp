

```markdown
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
```

### Example Input and Output
1. **Input (Before Sorting):**
    ```
    Array: [5, 3, 8, 6, 2]
    ```
2. **Output (After Sorting):**
    ```
    Array: [2, 3, 5, 6, 8]
    ```

## Complexity Analysis

| Case          | Time Complexity        | Explanation                                         |
|---------------|-------------------------|-----------------------------------------------------|
| **Best Case** | `O(n)`                 | Array is already sorted. Only one comparison per pass. |
| **Average Case** | `O(n^2)`            | Random order array. Comparisons and shifts dominate. |
| **Worst Case** | `O(n^2)`              | Array is sorted in reverse order. Maximum shifts required. |

### Space Complexity
- **Space Complexity:** `O(1)` (In-place sorting, no additional space required)

## Features
- Supports sorting arrays of types: `int`, `float`, `double`, `char`, and `string`.
- Uses C++ templates for type-generic implementation.
- Displays the array before and after sorting.

## How to Run
1. Compile the code:
    ```bash
    g++ -o insertion_sort insertion_sort.cpp
    ```
2. Run the executable:
    ```bash
    ./insertion_sort
    ```
3. Follow the instructions in the program to input array elements and data type.

## License
This project is open-source and available under the MIT License.
```

This `README.md` provides an overview of the algorithm, its complexity, and instructions to run the program in a structured and compact format.
