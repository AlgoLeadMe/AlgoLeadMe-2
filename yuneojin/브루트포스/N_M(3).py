import sys
input = sys.stdin.readline

n, m = map(int, input().split())

ans = [0 for i in range(m)]

def go(index, n, m):
    if (index == m):
        print(*ans)
        return
    for i in range(1, n+1):
        ans[index] = i
        go(index+1, n , m)

go(0, n, m)