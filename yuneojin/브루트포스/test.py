import sys
input = sys.stdin.readline

N = int(input())

ans = 0
len = 1
start = 1

while (start <= N):
    end = start*10-1
    if end > N:
        end = N
    ans += (end - start + 1)*len
    len += 1
    start *= 10
    
print(ans)