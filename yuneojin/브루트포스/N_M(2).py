import sys
_input = sys.stdin.readline

n, m = map(int, _input().split())

a = [0 for i in range(m)]

def go(index, selected, n, m):
    if selected == m:
        print(*a)
        return
    
    if index > n:
        return
    
    a[selected] = index
    go(index+1, selected+1, n, m)

    a[selected] = 0
    go(index+1, selected, n, m)

go(1, 0, n, m)