

```markdown
# Quick Sort Implementation in C++

This project implements the Quick Sort algorithm in C++ using templates for generic data types.

## Algorithm Explanation

Quick Sort is a divide-and-conquer algorithm that sorts an array by:
1. Selecting a pivot element.
2. Partitioning the array such that elements less than the pivot are on the left, and elements greater than the pivot are on the right.
3. Recursively applying the above steps to the subarrays.

### Code Breakdown
```cpp
template <typename T>
void quick_sort(T array[], int start, int end) {
    if (start < end) {
        T ptr = array[start]; // Pivot element
        int i = start, j = end;

        while (i < j) {
            while (array[i] <= ptr && i < end) i++; // Move right
            while (array[j] >= ptr && j > start) j--; // Move left
            if (i < j) MySwap(array[i], array[j]); // Swap elements
        }
        MySwap(array[j], array[start]); // Place pivot in correct position
        quick_sort(array, start, j - 1); // Sort left subarray
        quick_sort(array, j + 1, end); // Sort right subarray
    }
}
```

### Supporting Functions
- `MySwap`: Swaps two elements.
- `array_data`: Handles input and calls `quick_sort`.
- `show`: Displays the array.

### Input Flexibility
The program supports multiple data types: `int`, `float`, `double`, `char`, and `string`.

## Complexity Analysis

| Case        | Time Complexity | Description                                                                 |
|-------------|-----------------|-----------------------------------------------------------------------------|
| Best Case   | O(n log n)      | Pivot divides the array into two nearly equal parts for every recursion.    |
| Average Case| O(n log n)      | Partitioning is balanced on average.                                       |
| Worst Case  | O(n^2)          | Pivot is the smallest or largest element, leading to unbalanced partitions.|

### Space Complexity
- **O(log n)** (recursive stack space).

## Usage
1. Compile the program:
   ```bash
   g++ quick_sort.cpp -o quick_sort
   ```
2. Run the program:
   ```bash
   ./quick_sort
   ```
3. Follow prompts to input array size, data type, and elements.

## Example
Input:
```
Size: 5
Data Type: int
Elements: 3 1 4 1 5
```
Output:
```
Before sorting: 3, 1, 4, 1, 5
After sorting: 1, 1, 3, 4, 5
```

## Author
Created by [divesh2022](https://github.com/divesh2022)
```

This `README.md` provides an explanation of the algorithm, its complexity, and usage instructions in a structured and concise format.
