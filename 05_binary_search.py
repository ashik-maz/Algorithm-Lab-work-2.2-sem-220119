def binary_search(arr, key):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    return -1

array = list(map(int, input('Enter numbers: ').split()))
array.sort()
key = int(input('Enter search key: '))
result = binary_search(array, key)

if result != -1:
    print(f'Found at index {result}')
else:
    print('Not found')