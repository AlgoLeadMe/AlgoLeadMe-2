import sys

input = sys.stdin.readline

def next_permutation(arr, n):
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

def calculate(arr):
    temp = 0
    for i in range(n-1):
        temp += abs(arr[i]-arr[i+1])
    
    return temp

n = int(input())
numbers = list(map(int, input().split()))

numbers = sorted(numbers)
ans = calculate(numbers)

while(next_permutation(numbers, n) is True):
    temp = calculate(numbers)
    if ans < temp:
        ans = temp

print(ans)