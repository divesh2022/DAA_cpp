

```markdown
# Fractional Knapsack Problem

This program implements the **Fractional Knapsack Problem** using a greedy algorithm. The goal is to maximize the total value of items that can be accommodated in a knapsack with a given capacity. Unlike the 0/1 Knapsack problem, items can be divided into fractions.

```

## Algorithm

### Steps:
1. **Sort items**: Items are sorted in descending order based on their value-to-weight ratio.
2. **Iterate through items**:
   - If the item fits into the remaining capacity completely, include it fully.
   - If it doesn't fit, include the maximum fraction of the item that fits.
3. **Update total value and capacity** for every included item or fraction.
4. **Return the maximum value** and details of included items.

### Code:
```python
class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight

def fractional_knapsack(capacity, items):
    # Sort items by value-to-weight ratio in descending order
    items.sort(key=lambda item: item.value / item.weight, reverse=True)
    total_value = 0.0
    included_items = []
    for item in items:
        if capacity > 0 and item.weight <= capacity:
            # Fully include the item
            capacity -= item.weight
            total_value += item.value
            included_items.append((item.value, item.weight, 1.0))
        elif capacity > 0:
            # Include fraction of item
            fraction = capacity / item.weight
            total_value += item.value * fraction
            included_items.append((item.value, item.weight, fraction))
            break
    return total_value, included_items
```

---

## Time and Space Complexity

### Time Complexity:
- **Best Case**: `O(n log n)` (Sorting the items, with no iterations if capacity is zero).
- **Average Case**: `O(n log n)` (Sorting + Iterating through all `n` items).
- **Worst Case**: `O(n log n)` (Sorting + Iterating through all `n` items).

### Space Complexity:
- **Best, Average, Worst Case**: `O(n)` (Space for sorting and storing fractional items).

---

## Example Execution

### Input:
- **Items**: [(Value: 60, Weight: 10), (Value: 100, Weight: 20), (Value: 120, Weight: 30)]
- **Knapsack Capacity**: 50

### Output:
```
Maximum value: 240.00
Items included in the knapsack:
-> Value: 60, Weight: 10, Fraction taken: 1.00
-> Value: 100, Weight: 20, Fraction taken: 1.00
-> Value: 120, Weight: 30, Fraction taken: 0.67
```

---

## How to Run the Program
1. Clone the repository:
   ```bash
   git clone https://github.com/divesh2022/DAA_cpp.git
   cd DAA_cpp
   ```
2. Run the Python script:
   ```bash
   python fractionalKnapsack.py
   ```

---

## Applications
- Resource allocation problems.
- Maximizing profit in constrained environments.
- Solving optimization problems with divisible resources.

---
``` 

This README.md provides a compact explanation of the algorithm, its complexity, and usage instructions.
