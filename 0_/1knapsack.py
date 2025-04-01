# write a program to solve 0/1 knapsack problem using dynamic programming

def knapsack(values, weights, capacity):
    n = len(values)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    print("intializing dp table")
    for i in dp:
        print(i)
    print("\n")
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]
    print("Final dp table")
    for i in dp:
        print(i)
    print("\n")
    # Backtrack to find the items included in the knapsack
    w = capacity
    selected_items = []
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:  # Item i-1 was included
            selected_items.append((values[i - 1], weights[i - 1]))
            w -= weights[i - 1]

    return dp[n][capacity], selected_items 

if __name__ == "__main__":
    values = [60, 100, 120]
    weights = [1, 2, 3]
    capacity = 5

    print("\nDynamic Programming Table:")
    max_value, selected_items  = knapsack(values, weights, capacity)
    print(f"\nMaximum value that can be accommodated in the knapsack: {max_value}")
    print("\nItems included in the knapsack:")
    for value, weight in selected_items:
        print(f"Value: {value}, Weight: {weight}")

