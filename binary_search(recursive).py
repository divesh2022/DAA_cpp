def binary_search_i(lst, start, stop, key):
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
def binary_search_r(lst, key):
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
def check(res):
        if res != False:
        print("Element found at index", res)
    else:
        print("Element not found")
def main():
    lst = input("Enter the list of numbers separated by hyphens: ")
    lst = lst.split("-")
    num_list = [int(i) for i in lst]
    print("Unsorted list is", lst)
    sorted_list = sorted(num_list)
    print("Sorted list is", sorted_list)
    key = int(input("Enter value to find: "))
    a = input("enter your choice  : ")
    if (a == 0):
        res1 = binary_search(sorted_list, 0, len(sorted_list) - 1, key)
        check(res1)
    elif (a == 1):
        res2 = binary_search_i(sorted_list, 0, len(sorted_list) - 1, key)
        check(res2)
    else:
        print("invalid choice")
n = int(input("Enter the number of test cases: "))
for i in range(n):
    main()
