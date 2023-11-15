import sys
input = sys.stdin.readline

test = int(input())

for i in range(test):
    M, N, x, y = map(int, input().split())

    x = x-1
    y = y-1
    found = False
    
    for k in range(x, N*M, M):
        if k%N == y:
            print(k+1)
            found = True
            break
    
    if found is False:
        print(-1)