import sys
input = sys.stdin.readline

n = int(input())
candy = [list(input().rstrip()) for i in range(n)]
ans = 0

def check(c):
    ans = 1
    for i in range(n):
        cnt = 1
        for j in range(1, n):
            if (candy[i][j] == candy[i][j-1]):
                cnt += 1
            else:
                cnt = 1
            if cnt > ans:
                ans = cnt
        cnt = 1
        for j in range(1, n):
            if candy[j][i] == candy[j-1][i]:
                cnt += 1
            else:
                cnt =1
            if cnt > ans:
                ans = cnt
    return ans

for i in range(n):
    for j in range(n):
        if (j+1 < n):
            candy[i][j+1], candy[i][j] = candy[i][j], candy[i][j+1]
            tmp = check(candy)
            if ans < tmp:
                ans = tmp
            candy[i][j+1], candy[i][j] = candy[i][j], candy[i][j+1]

        if (i+1 < n):
            candy[i][j], candy[i+1][j] = candy[i+1][j], candy[i][j]
            tmp = check(candy)
            if ans < tmp:
                ans = tmp
            candy[i][j], candy[i+1][j] = candy[i+1][j], candy[i][j]

print(ans)