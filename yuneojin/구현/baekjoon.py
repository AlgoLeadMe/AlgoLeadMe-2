import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

broken = [False for i in range(10)]

def possible(c):
    if c==0:
        if broken[0]:
            return 0
        else:
            return 1
    len = 0
    while c>0:
        if broken[c % 10]:
            return 0
        len += 1
        c//=10
    return len

if m != 0:
    b = list(map(int, input().split()))
    for i in b:
        broken[i] = True

ans = abs(n - 100)

for i in range(1000001):
    c = i
    tmp = possible(c)
    if tmp != 0:
        tmp += abs(c-n)
        if ans > tmp:
            ans = tmp

print(ans)
