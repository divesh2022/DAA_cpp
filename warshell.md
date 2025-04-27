
# Floyd-Warshall Algorithm Implementation

This Python script implements the **Floyd-Warshall Algorithm** to find the shortest paths between all pairs of vertices in a given weighted graph. It uses an adjacency matrix representation for the graph and outputs the All-Pairs Shortest Path matrix.

## Algorithm Explanation
The **Floyd-Warshall Algorithm** is a dynamic programming algorithm for finding the shortest paths between all pairs of vertices in a graph. The algorithm works in three nested loops:
1. Iterates through each vertex as an intermediate node (`k`).
2. Updates the shortest path between every pair of vertices (`i` and `j`) using the intermediate node.

### Code Implementation
```python
INF = float('inf')  # Represents infinity

def floyd_warshall(graph):
    num_vertices = len(graph)
    dist = [[graph[i][j] for j in range(num_vertices)] for i in range(num_vertices)]

    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                if dist[i][k] != INF and dist[k][j] != INF:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    return dist
```
### Input Example
- **Graph:** Adjacency matrix representation:
  ```
  [[0, 3, INF, 5],
   [2, 0, INF, 4],
   [INF, 1, 0, INF],
   [INF, INF, 2, 0]]
  ```

### Output
- The All-Pairs Shortest Path matrix:
  ```
  [[0, 3, 7, 5],
   [2, 0, 6, 4],
   [3, 1, 0, 5],
   [5, 3, 2, 0]]
  ```

## Time and Space Complexity
### Time Complexity
- **Best Case:** O(V³)
- **Average Case:** O(V³)
- **Worst Case:** O(V³)
  - The algorithm requires three nested loops over the vertices.

### Space Complexity
- **Best Case:** O(V²)
- **Average Case:** O(V²)
- **Worst Case:** O(V²)
  - Space is used for storing the distance matrix.

## Dependencies
- Python 3+
- Libraries: `pandas` (for formatted matrix display)

## How to Run
1. Install dependencies: `pip install pandas`
2. Execute the script: `python warshell.py`

## Example Output
```
Original Graph:
      A    B    C    D
A  0.0  3.0  inf  5.0
B  2.0  0.0  inf  4.0
C  inf  1.0  0.0  inf
D  inf  inf  2.0  0.0

All-Pairs Shortest Path Matrix:
   A  B  C  D
A  0  3  7  5
B  2  0  6  4
C  3  1  0  5
D  5  3  2  0
```

## License
This script is part of the `DAA_cpp` repository for Design and Analysis of Algorithms coursework.
```

You can save the above content as a `README.md` file in the same directory as the `warshell.py` script.
