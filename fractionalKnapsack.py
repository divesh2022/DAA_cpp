class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight

def fractional_knapsack(capacity, items):
    items.sort(key=lambda item: item.value / item.weight, reverse=True)
    total_value = 0.0
    included_items = []
    for item in items:
        if capacity > 0 and item.weight <= capacity:
            capacity -= item.weight
            total_value += item.value
            included_items.append((item.value, item.weight, 1.0))
        elif capacity > 0:
            fraction = capacity / item.weight
            total_value += item.value * fraction
            included_items.append((item.value, item.weight, fraction))
            capacity = 0
    return total_value, included_items

if __name__ == "__main__":
    items = [Item(60, 10), Item(100, 20), 
             Item(120, 30), Item(50, 50), 
             Item(60, 70), Item(40, 50)]
    capacity = 50
    max_value, included_items = fractional_knapsack(capacity, items)
    print(f'''The maximum value that can be accommodated in 
          the knapsack is: {max_value:.2f}''')
    print("Items included in the knapsack:")
    for value, weight, fraction in included_items:
        print("-> Value:", value)
        print("   Weight:", weight)  
        print("   Fraction taken: {:.2f}".format(fraction))
'''
output : 
The maximum value that can be accommodated in 
          the knapsack is: 240.00
Items included in the knapsack:
-> Value: 60
   Weight: 10
   Fraction taken: 1.00
-> Value: 100
   Weight: 20
   Fraction taken: 1.00
-> Value: 120
   Weight: 30
   Fraction taken: 0.67
'''
