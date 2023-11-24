import sys
input = sys.stdin.readline

n = int(input())
s = [[0 for i in range(n)]for j in range(n)]
start = []
link = []

def go(index, start, link):
    if index == n:  # 팀 뽑기 완료 시
        if (len(start) != n/2):
            return -1
        if (len(link) != n/2):
            return -1
        team1 = 0
        team2 = 0
        for i in range(n//2):
            for j in range(n//2):
                if i == j:
                    continue
                team1 += s[start[i]][start[j]]
                team2 += s[link[i]][link[j]]
        diff = abs(team1 - team2)
        return diff
    
    if len(start) > n/2:
        return -1
    if len(link) > n/2:
        return -1
    
    ans = -1
    start.append(index)
    team1 = go(index+1, start, link)
    print(start)
    print(link)
    if ans == -1 or (team1 != -1 and ans > team1):
        ans = team1
    start.remove(index)

    link.append(index)
    team2 = go(index+1, start, link)
    print(start)
    print(link)
    if ans == -1 or (team2 != -1 and ans > team2):
        ans = team2
    link.remove(index)

    return ans

for i in range(n):
    s[i] = list(map(int, input().split()))

print(go(0, start, link))