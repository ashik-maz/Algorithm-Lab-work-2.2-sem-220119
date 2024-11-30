import random
import time

def linear_search(arr,target):
    count = 0
    for i in range(len(arr)):
        count += 1
        if arr[i] == target:
            return i,count
    return -1, count

def binary_search(arr,target):
    low, high = 0, len(arr)-1
    count = 0
    while low <= high:
        count += 1
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid,count
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1, count

def generate_usernames (n):
    usernames = ['user'+str(i) for i in range(n)]
    random.shuffle(usernames)
    return usernames

def compare_searches ():
    num_username = 100000
    usernames = generate_usernames(num_username)
    sorted_usernames = sorted(usernames)

    target = random.choice(usernames)

    start_time = time.perf_counter()
    linear_index, linear_count = linear_search(usernames, target)
    linear_time = time.perf_counter() - start_time

    start_time = time.perf_counter()
    binary_index, binary_count = binary_search(sorted_usernames, target)
    binary_time = time.perf_counter() - start_time

    print(f'Linear Search: Time = {linear_time: .6f} seconds, {linear_count} comparisons, Target index = {linear_index} and Target String = {target}')
    print(f'Binary Search: Time = {binary_time: .6f} seconds, {binary_count} comparisons, Target index = {binary_index} and Target String = {target}')

compare_searches()