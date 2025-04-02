from queue import PriorityQueue

class Node:
    def __init__(self, level, value, weight, bound, items):
        self.level = level  # Level of the node in the decision tree
        self.value = value  # Total value so far
        self.weight = weight  # Total weight so far
        self.bound = bound  # Upper bound of the maximum value
        self.items = items  # List of items included in this node

    def __lt__(self, other):
        return self.bound > other.bound  # Priority queue uses the highest bound first

def bound(node, n, capacity, values, weights):
    if node.weight >= capacity:
        return 0  # If weight exceeds capacity, bound is 0

    profit_bound = node.value
    j = node.level + 1
    total_weight = node.weight

    while j < n and total_weight + weights[j] <= capacity:
        total_weight += weights[j]
        profit_bound += values[j]
        j += 1

    if j < n:
        profit_bound += (capacity - total_weight) * (values[j] / weights[j])

    return profit_bound

def knapsack_branch_and_bound(values, weights, capacity):
    n = len(values)
    items = sorted(zip(values, weights), key=lambda x: x[0] / x[1], reverse=True)
    values, weights = zip(*items)

    pq = PriorityQueue()
    root = Node(level=-1, value=0, weight=0, bound=0, items=[])
    root.bound = bound(root, n, capacity, values, weights)
    pq.put(root)

    max_value = 0
    best_items = []

    while not pq.empty():
        current = pq.get()

        if current.bound > max_value:
            next_level = current.level + 1

            if next_level < n:
                # Include the next item
                include = Node(
                    level=next_level,
                    value=current.value + values[next_level],
                    weight=current.weight + weights[next_level],
                    bound=0,
                    items=current.items + [(values[next_level], weights[next_level])]
                )
                if include.weight <= capacity:
                    if include.value > max_value:
                        max_value = include.value
                        best_items = include.items
                    include.bound = bound(include, n, capacity, values, weights)
                    if include.bound > max_value:
                        pq.put(include)

                # Exclude the next item
                exclude = Node(
                    level=next_level,
                    value=current.value,
                    weight=current.weight,
                    bound=0,
                    items=current.items
                )
                exclude.bound = bound(exclude, n, capacity, values, weights)
                if exclude.bound > max_value:
                    pq.put(exclude)

    return max_value, best_items

if __name__ == "__main__":
    values = [60, 110, 100, 120, 150]
    weights = [3, 2, 4, 5, 6]
    capacity = 7

    max_value, selected_items = knapsack_branch_and_bound(values, weights, capacity)

    print(f"\nMaximum value that can be accommodated in the knapsack: {max_value}")
    print("\nItems included in the knapsack:")
    for value, weight in selected_items:
        print(f"Value: {value}, Weight: {weight}")
