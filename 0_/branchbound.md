
---

# 0/1 Knapsack Problem using Branch and Bound

This repository contains a Python implementation of the 0/1 Knapsack problem solved using the Branch and Bound method. The goal of the 0/1 Knapsack problem is to maximize the total value of items that can be included in a knapsack of fixed capacity, where each item can either be included or excluded from the knapsack.

## Description

The Branch and Bound method is an optimization algorithm that systematically explores the decision tree to find the optimal solution to the 0/1 Knapsack problem. This implementation uses a priority queue to explore nodes with the highest upper bound values first, pruning suboptimal branches to improve efficiency.

## Usage

1. **Dependencies**: Ensure you have Python installed on your system.

2. **Clone the Repository**:
    ```sh
    git clone https://github.com/divesh2022/DAA_cpp.git
    cd DAA_cpp
    ```

3. **Run the Program**:
    Execute the Python script to solve the 0/1 Knapsack problem with predefined values and weights:
    ```sh
    python 0_/1knapsack_branchbound.py
    ```

4. **Example Output**:
    ```
    Maximum value that can be accommodated in the knapsack: 220
    
    Items included in the knapsack:
    Value: 110, Weight: 2
    Value: 100, Weight: 4
    ```

## Code Explanation

The code includes the following key components:

1. **Node Class**:
    - Represents a node in the decision tree.
    - Stores the level, total value, weight, upper bound, and list of items included in the node.

2. **Bound Function**:
    - Calculates the upper bound of the maximum value for a given node.

3. **Knapsack Branch and Bound Function**:
    - Implements the Branch and Bound algorithm to solve the 0/1 Knapsack problem.
    - Utilizes a priority queue to explore nodes with the highest bound values first.
    - Returns the maximum value and the list of items included in the optimal solution.

4. **Main Function**:
    - Defines the values, weights, and capacity of the knapsack.
    - Calls the `knapsack_branch_and_bound` function and prints the results.

## Customization

You can modify the `values`, `weights`, and `capacity` variables in the script to solve different instances of the 0/1 Knapsack problem. Simply update the arrays and the capacity value in the `__main__` section of the script.

```python
if __name__ == "__main__":
    values = [60, 110, 100, 120, 150]
    weights = [3, 2, 4, 5, 6]
    capacity = 7

    max_value, selected_items = knapsack_branch_and_bound(values, weights, capacity)

    print(f"\nMaximum value that can be accommodated in the knapsack: {max_value}")
    print("\nItems included in the knapsack:")
    for value, weight in selected_items:
        print(f"Value: {value}, Weight: {weight}")
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
