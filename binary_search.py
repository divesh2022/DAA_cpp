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

def sorting(lst):
    for _ in range(len(lst)):
        for j in range(len(lst)-1):
            if lst[j] > lst[j+1]:
                temp = lst[j]
                lst[j] = lst[j+1]
                lst[j+1] = temp
    return lst

def main():
    lst = input("Enter the list of numbers separated by hyphens: ")
    lst = lst.split("-")
    print("Unsorted list is", lst)
    a = []
    for i in lst:
        a.append(int(i))
    a = sorting(a)
    print("Sorted list is", a)
    key = int(input("Enter value to find: "))
    print("Sorted list is", a)
    res = binary_search(a, 0, len(a)-1, key)
    if res != False:
        print("Element found at index", res)
    else:
        print("Element not found")

n = int(input("Enter the number of test cases: "))
for i in range(n):
    main()
