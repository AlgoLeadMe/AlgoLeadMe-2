import sys
input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))

def next_premutaiont(arr, n):
    i = n-1
    while i > 0 and arr[i-1] >= arr[i]: i -= 1
    if i <= 0: return False
    j = n-1
    while(j >= i and arr[j] <= arr[i-1]): j -= 1
    arr[i-1], arr[j] = arr[j], arr[i-1]
    j = n-1
    while(i < j):
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1
    return True

if (next_premutaiont(arr, n)): print(*arr)
else: print(-1)
