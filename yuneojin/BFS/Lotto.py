# import sys
# import itertools

# input = sys.stdin.readline

# while True:
#     arr = list(map(int, input().split()))
#     k = arr[0]
#     s = arr[1:]

#     for i in itertools.combinations(s, 6):
#         print(*i)
#     print('')

#     if k == 0:
#         break

import sys

input = sys.stdin.readline


def dfs(depth, idx):
    if depth == 6:
        print(*out)
        return
    
    for i in range(idx, k):
        out.append(s[i])
        dfs(depth + 1, i + 1)
        out.pop()

        
while True:
    arr = list(map(int, input().split()))
    k = arr[0]
    s = arr[1:]
    out = []
    dfs(0, 0)
    if k == 0:
        break
    print()