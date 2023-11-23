# https://school.programmers.co.kr/learn/courses/30/lessons/43164
# 여행경로

def solution(tickets):
    answer = []
    visited = [False]*len(tickets)

    def dfs(current, path):
        # 노드들(path)의 개수 = 간선들(tickets)의 개수 + 1
        if len(path) == len(tickets)+1:
            answer.append(path)
            return

        for idx, ticket in enumerate(tickets):
            if visited[idx]:
                continue

            a, b = ticket
            if current == a:
                visited[idx] = True
                dfs(b, path + [b])
                visited[idx] = False

    dfs("ICN", ["ICN"])
    answer.sort()

    return answer[0]

