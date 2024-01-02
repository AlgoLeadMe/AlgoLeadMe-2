import sys
input = sys.stdin.readline

def go(index):
    if index == n:
        return True
    
    if sign[index][index] == 0:
        ans[index] = 0
        return check(index) and go(index+1)
    
    for i in range(1, 11):
        ans[index] = sign[index][index]*i
        if check(index) and (go(index+1)):
            return True
    return False

def check(index):
    sum = 0
    for i in range(index, -1, -1):
        sum += ans[i]
        if (sign[i][index] == 0):
            if sum != 0:
                return False
        if (sign[i][index] < 0):
            if sum >= 0:
                return False
        if (sign[i][index] > 0):
            if sum <= 0:
                return False
    return True

n = int(input())
arr = list(input())
sign = [[0 for i in range(n)]for j in range(n)]

for i in range(n):
    for j in range(i, n):
        tmp = arr.pop(0)
        if tmp == '+':
            sign[i][j] = 1
        elif tmp == '-':
            sign[i][j] = -1

ans = [0 for _ in range(n)]
go(0)
print(*ans)