def max_min_divide_conquer(arr, low, high, cnt):
    if low == high:
        cnt += 1
        return arr[low], arr[low], cnt
    elif high == low + 1:
        cnt += 2
        if arr[low] > arr[high]:
            return arr[low], arr[high], cnt
        else:
            return arr[high], arr[low], cnt

    mid = (low+high) // 2
    left_max, left_min , cnt = max_min_divide_conquer(arr, low, mid, cnt)
    right_max, right_min, cnt = max_min_divide_conquer(arr, mid+1, high, cnt)

    final_mx = max(left_max, right_max)
    final_mn = min(left_min, right_min)
    cnt += 2
    return final_mx, final_mn, cnt

numbers = list(map(int,input('Enter numbers: ').split()))
count = 0
max_value, min_value, total_count = max_min_divide_conquer(numbers, 0, len(numbers)-1, count)
print(f'Max value : {max_value} and Min value : {min_value} and Order of n (Steps) : {total_count}')