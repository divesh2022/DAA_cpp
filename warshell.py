# find all pair shortest path
import pandas as pd

INF = float('inf')
def floyd_warshall(graph):
    num_vertices = len(graph)
    dist = [[graph[i][j] for j in range(num_vertices)] for i in range(num_vertices)]

    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                if dist[i][k] != INF and dist[k][j] != INF:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    return dist

if __name__ == "__main__":
    vertex = ['A', 'B', 'C', 'D']
    graph = [[0, 3, INF, 5],[2, 0, INF, 4],
        [INF, 1, 0, INF],[INF, INF, 2, 0]]
    df = pd.DataFrame(graph, index = vertex, columns = vertex)
    print("orignal graph\n",df)
    graph = floyd_warshall(graph)
    df = pd.DataFrame(graph, index=vertex, columns=vertex)
    print("All-Pairs Shortest Path Matrix:\n",df)
'''
output:
orignal graph
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
'''
