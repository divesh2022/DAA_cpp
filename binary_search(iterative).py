def binary_search(lst, key):
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
def main():
    lst = input("Enter the list of numbers separated by hyphens: ")
    lst = lst.split("-")
    print("Unsorted list is", lst)
    num_list = [int(i) for i in lst]
    sorted_list = sorted(num_list)
    print("Sorted list is", sorted_list)
    key = int(input("Enter value to find: "))
    res = binary_search(sorted_list, key)
    if res != False:
        print("Element found at index", res)
    else:
        print("Element not found")
n = int(input("Enter the number of test cases: "))
for i in range(n):
    main()
