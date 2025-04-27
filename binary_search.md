


# Binary Search (Recursive and Iterative)

This Python script implements the **Binary Search** algorithm in both recursive and iterative approaches. Binary Search is a classic algorithm used to find the position of a target element within a sorted list.

---

## Algorithms Implemented

### Recursive Binary Search (`binary_search_i`)
```python
def binary_search_i(lst, start, stop, key):
    if start > stop:
        return False
    else:
        mid = (start + stop) // 2
        if key == lst[mid]:
            return mid
        elif key < lst[mid]:
            return binary_search(lst, start, mid-1, key)
        else:
            return binary_search(lst, mid+1, stop, key)
```

### Iterative Binary Search (`binary_search_r`)
```python
def binary_search_r(lst, key):
    start, stop = 0, len(lst) - 1
    while start <= stop:
        mid = (start + stop) // 2
        if key == lst[mid]:
            return mid
        elif key < lst[mid]:
            stop = mid - 1
        else:
            start = mid + 1
    return False
```

---

## Time Complexity

| Case        | Recursive Binary Search | Iterative Binary Search |
|-------------|--------------------------|--------------------------|
| Best Case   | O(1)                    | O(1)                    |
| Average Case| O(log n)                | O(log n)                |
| Worst Case  | O(log n)                | O(log n)                |

---

## Space Complexity

| Case        | Recursive Binary Search | Iterative Binary Search |
|-------------|--------------------------|--------------------------|
| Best/Worst  | O(log n) (due to recursion stack) | O(1) (in-place iteration) |

---

## How the Code Works

1. **Input**: The user provides a list of integers (separated by hyphens) and a key to search for.
2. **Sorting**: The input list is sorted using Python's built-in `sorted()` function.
3. **Choice**: The user selects:
   - `0` for Recursive Binary Search
   - `1` for Iterative Binary Search
4. **Execution**: The chosen algorithm is applied to find the key in the sorted list.
5. **Output**: The index of the key (if found) or a message indicating that the key is not present.

---

## Example Usage

```plaintext
Enter the list of numbers separated by hyphens: 5-2-9-1
Unsorted list is ['5', '2', '9', '1']
Sorted list is [1, 2, 5, 9]
Enter value to find: 5
enter your choice  : 1
Element found at index 2
```

---

## Notes

- Ensure the input list only contains integers.
- The script supports multiple test cases in a single run.

This file demonstrates the efficiency of Binary Search in solving search problems for sorted data while comparing recursive and iterative implementations.
```
