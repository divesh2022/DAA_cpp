
# N-Queens Problem Solver

This Python script solves the classic **N-Queens problem** using a backtracking algorithm. The goal of the problem is to place `N` queens on an `N x N` chessboard such that no two queens threaten each other. This means:
- No two queens share the same row, column, or diagonal.

## Algorithm Explanation

The solution is implemented using **Backtracking**, a depth-first search approach. Here's an overview of the algorithm:

1. **Backtracking Function (`solve_n_queens_util`)**:
   - Recursively tries to place queens column by column.
   - For each column, checks all rows to find a safe position for the queen.
   - If a valid position is found for a queen, it proceeds to the next column.
   - If no valid position exists, it backtracks by removing the previously placed queen.

2. **Safety Check (`is_safe`)**:
   - Ensures that placing a queen at a specific position does not conflict with any already-placed queens.
   - Checks:
     - Leftwards on the same row.
     - Upper-left diagonal.
     - Lower-left diagonal.

3. **Solution Printing (`print_solution`)**:
   - Displays the board configuration for each valid solution.

### Code Example
Below is a simplified representation of the backtracking approach in pseudocode:
```python
def solve_n_queens_util(board, col, n):
    if col >= n:
        print_solution(board)  # Print the board if all queens are placed
        return True
    
    for row in range(n):  # Try placing queen in all rows of the current column
        if is_safe(board, row, col, n):
            board[row][col] = 1  # Place queen
            solve_n_queens_util(board, col + 1, n)  # Recursively place queens
            board[row][col] = 0  # Backtrack if no solution is found
```

### Complexity Analysis

| **Aspect**       | **Best Case**    | **Average Case** | **Worst Case**    |
|-------------------|------------------|------------------|-------------------|
| **Time Complexity** | `O(N!)`         | `O(N!)`          | `O(N!)`           |
| **Space Complexity**| `O(N^2)`        | `O(N^2)`         | `O(N^2)`          |

- **Time Complexity**: The algorithm explores all possible placements of queens, leading to factorial growth (`N!`) in the number of possibilities.
- **Space Complexity**: The board is represented as a 2D array of size `N x N`.

### How to Use

1. Run the script:
   ```bash
   python Nqueen.py
   ```
2. Input:
   - The number of test cases (`t`).
   - The number of queens (`n`) for each test case.
3. Output:
   - Prints all valid solutions for the given `n`.
   - Displays the total number of solutions.

### Example
Input:
```
enter no of test cases : 1
enter the number of queens : 4
```

Output:
```
. Q . .
. . . Q
Q . . .
. . Q .

. . Q .
Q . . .
. . . Q
. Q . .

Total solutions found: 2
```

### References
- [N-Queens Problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle)
``` 

This `README.md` provides a structured overview of the script, including the algorithm, complexity, usage instructions, and examples.
