import time

def linear_max_min(arr, cnt):
    max_v = min_v = arr[0]
    for num in arr[1:]:
        cnt+=1
        if num > max_v:
            max_v = num
        if num < min_v:
            min_v = num
    return max_v, min_v, cnt

def divide_and_conquer_max_min(arr, low, high, cnt):
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
    left_max, left_min , cnt = divide_and_conquer_max_min(arr, low, mid, cnt)
    right_max, right_min, cnt = divide_and_conquer_max_min(arr, mid+1, high, cnt)

    final_mx = max(left_max, right_max)
    final_mn = min(left_min, right_min)
    cnt += 2
    return final_mx, final_mn, cnt

def main():
    while True:
        print('\nMenu\n1. Find in Linear\n2. Find in Divide&Conquer\n3. Exit')
        choice_1 = int(input('Enter your choice: '))
        if choice_1 == 3:
            print('Exiting... Thank You!')
            break
        elif choice_1 in [1, 2]:
            numbers = list(map(int, input('Enter numbers: ').split()))
            if not numbers:
                print("The list is empty! Please provide valid input.")
                continue
            count = 0
            if choice_1 == 1:
                start_time = time.perf_counter()
                Lmax_value, Lmin_value, Lcount = linear_max_min(numbers, count)
                total_time = time.perf_counter() - start_time
                print(f'The max number is: {Lmax_value} The min number is: {Lmin_value} Time taken: {total_time : .6f} Steps: {Lcount}')
            elif choice_1 == 2:
                start_time = time.perf_counter()
                Rmax_value, Rmin_value, Rcount = divide_and_conquer_max_min(numbers, 0, len(numbers)-1, count)
                total_time = time.perf_counter() - start_time
                print(f'The max number is: {Rmax_value} The min number is: {Rmin_value} Time taken: {total_time : .6f} Steps: {Rcount}')
        else:
            print('Invalid Choice! Please try again.')

main()