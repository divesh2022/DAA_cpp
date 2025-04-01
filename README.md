
---

# Design and Analysis of Algorithms (DAA)

Welcome to the `DAA_cpp` repository! This repository contains various programs and scripts related to the design and analysis of algorithms. The primary languages used in this repository are C++, Python, and C.

## Repository Structure

The repository is organized as follows:

- **C++ Scripts**: Contains C++ programs for various algorithmic problems and solutions.
- **Python Scripts**: Contains Python scripts for solving algorithmic problems using different approaches.
- **C Scripts**: Includes C programs for foundational algorithms and data structures.

## Getting Started

To get started with this repository, follow the steps below:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/divesh2022/DAA_cpp.git
   cd DAA_cpp
   ```

2. **Compile and Run C++ Programs**:
   - Ensure you have a C++ compiler installed (e.g., `g++`).
   - Compile a C++ program:
     ```bash
     g++ -o output_file program.cpp
     ```
   - Run the compiled program:
     ```bash
     ./output_file
     ```

3. **Run Python Scripts**:
   - Ensure you have Python installed on your system.
   - Run a Python script:
     ```bash
     python script.py
     ```

4. **Compile and Run C Programs**:
   - Ensure you have a C compiler installed (e.g., `gcc`).
   - Compile a C program:
     ```bash
     gcc -o output_file program.c
     ```
   - Run the compiled program:
     ```bash
     ./output_file
     ```

## Example Programs

### C++ Example: 0/1 Knapsack Problem

The `0_/1knapsack.py` script solves the 0/1 Knapsack problem using dynamic programming. Here is a brief overview of the script:

```python
def knapsack(values, weights, capacity):
    n = len(values)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]
    w = capacity
    selected_items = []
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:
            selected_items.append((values[i - 1], weights[i - 1]))
            w -= weights[i - 1]
    return dp[n][capacity], selected_items 

if __name__ == "__main__":
    values = [60, 100, 120]
    weights = [1, 2, 3]
    capacity = 5
    max_value, selected_items  = knapsack(values, weights, capacity)
    print(f"Maximum value: {max_value}")
    print("Items included:")
    for value, weight in selected_items:
        print(f"Value: {value}, Weight: {weight}")
```

## Contributing

We welcome contributions to this repository! If you have any improvements or new algorithms to add, please follow these steps:

1. Fork the repository.
2. Create a new branch with your feature or bug fix:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Description of feature or fix"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Create a pull request detailing your changes.

## Issues

If you encounter any issues or have any questions, feel free to open an issue in the repository's [issue tracker](https://github.com/divesh2022/DAA_cpp/issues).

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgments

Thanks to everyone who has contributed to this project!

---
