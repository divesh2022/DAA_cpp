

```markdown
# Merge Sort Implementation

This file implements the **Merge Sort** algorithm in C++ using templates to support multiple data types (e.g., `int`, `float`, `double`, `char`, `string`).

## Algorithm Explanation

Merge Sort is a **divide-and-conquer algorithm** that recursively splits an array into smaller subarrays, sorts them, and merges them back together. Below is the structured explanation of the algorithm:

### Steps:
1. **Divide**: Recursively divide the array into two halves until each subarray has only one element.
2. **Conquer**: Merge two sorted subarrays into a single sorted array.
3. **Combine**: Combine the results of the previous step to get a fully sorted array.

### Code Walkthrough
```cpp
template <typename T>
void merge(T array[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create temporary arrays for left and right halves
    T* left = new T[n1];
    T* right = new T[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) left[i] = array[start + i];
    for (int j = 0; j < n2; j++) right[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) array[k++] = left[i++];
        else array[k++] = right[j++];
    }

    // Copy remaining elements from left and right arrays
    while (i < n1) array[k++] = left[i++];
    while (j < n2) array[k++] = right[j++];

    // Free allocated memory
    delete[] left;
    delete[] right;
}

template <typename T>
void merge_sort(T array[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_sort(array, start, mid);   // Sort left half
        merge_sort(array, mid + 1, end); // Sort right half
        merge(array, start, mid, end);  // Merge the two halves
    }
}
```

The file also includes an interactive interface to:
1. Input the size and data type of the array (e.g., `int`, `float`, etc.).
2. Enter array elements.
3. Display the array before and after sorting.

## Complexity Analysis

| Case          | Time Complexity     | Space Complexity |
|---------------|---------------------|------------------|
| Best Case     | `O(n log n)`        | `O(n)`           |
| Average Case  | `O(n log n)`        | `O(n)`           |
| Worst Case    | `O(n log n)`        | `O(n)`           |

### Time Complexity Breakdown:
1. Divide step: Splitting the array takes `O(log n)` because the array is halved at each step.
2. Merge step: Merging two sorted subarrays takes `O(n)` for each level of recursion.
3. Total: Multiply the above steps → `O(n log n)`.

### Space Complexity:
- Requires temporary arrays for merging, resulting in `O(n)` auxiliary space.

## How to Run

1. Compile the program:
   ```bash
   g++ -o merge_sort merge_sort.cpp
   ```
2. Run the program:
   ```bash
   ./merge_sort
   ```
3. Follow the interactive prompts to input array details and view sorted results.

## Example Input/Output
### Input:
```
Enter the size of the array: 5
Valid data types are int, float, double, char, string
Enter data type of the array: int
Enter data at index 0: 4
Enter data at index 1: 2
Enter data at index 2: 3
Enter data at index 3: 1
Enter data at index 4: 5
```

### Output:
```
Before sorting:
A[0] = 4
A[1] = 2
A[2] = 3
A[3] = 1
A[4] = 5
After sorting:
A[0] = 1
A[1] = 2
A[2] = 3
A[3] = 4
A[4] = 5
```

## Additional Information
The program supports sorting arrays of the following data types:
- `int`
- `float`
- `double`
- `char`
- `string`

## Contributing
Feel free to contribute to this repository by adding more algorithms or improving existing ones.

---

```
