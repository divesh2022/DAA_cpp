def binary_search(lst, start, stop, key):
    if start > stop:
        return False
    else:
        mid = (start + stop) // 2
        if key == lst[mid]:
            return mid
        elif key < lst[mid]:
            return binary_search(lst, start, mid-1, key)
        else:
            return binary_search(lst, mid+1, stop, key)
def main():
    lst = input("Enter the list of numbers separated by hyphens: ")
    lst = lst.split("-")
    print("Unsorted list is", lst)
    num_list = [int(i) for i in lst]
    sorted_list = sorted(num_list)
    print("Sorted list is", sorted_list)
    key = int(input("Enter value to find: "))
    res = binary_search(sorted_list, 0, len(sorted_list) - 1, key)
    if res != False:
        print("Element found at index", res)
    else:
        print("Element not found")
n = int(input("Enter the number of test cases: "))
for i in range(n):
    main()
