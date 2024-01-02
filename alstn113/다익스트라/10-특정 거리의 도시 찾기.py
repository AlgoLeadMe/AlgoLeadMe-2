import sys
import heapq

input = sys.stdin.readline
INF = 1e9

# N: 노드의 개수, M: 간선의 개수, K: 최단 거리, X: 출발 노드
N, M, K, X = map(int, input().split())

graph = [[] for _ in range(N+1)]
distance = [INF]*(N+1)

for _ in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)


# 간단하게 말해서 a -> b와 a -> k -> b 중 더 짧은 거리로 갱신하는 것이다.
def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + 1  # 모든 간선의 가중치가 1이라고 가정
            if cost < distance[i]:
                distance[i] = cost
                heapq.heappush(q, (cost, i))


dijkstra(X)

result = [i for i in range(1, N+1) if distance[i] == K]

if result:
    for node in result:
        print(node)
else:
    print(-1)
