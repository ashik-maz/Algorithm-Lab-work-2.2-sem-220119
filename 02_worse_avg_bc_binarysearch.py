def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    count = 0

    while low <= high:
        count += 1
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid, count
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1, count


# Main program
print("Choose a case to simulate:")
print("1. Average case (target is in the array)")
print("2. Worst case (target is not in the array)")
choice = int(input("Enter your choice (1 or 2): "))

arr = list(map(int, input("Enter a sorted array (space-separated): ").split()))
arr.sort()
if choice == 1:
    target = int(input("Enter the target element (must exist in the array): "))
elif choice == 2:
    target = int(input("Enter the target element (not in the array): "))
else:
    print("Invalid choice")
    exit()

index, count = binary_search(arr, target)

if index != -1:
    print(f"Target found at index {index}.")
else:
    print("Target not found in the array.")
print(f"Total loop iterations: {count}")