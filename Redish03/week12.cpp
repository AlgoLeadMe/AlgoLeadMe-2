#include <iostream>
#include <queue>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
queue<pair<int, int>> q;
int N, M;
int arr[1001][1001];
int visited[1001][1001];

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 맨 첫 번째 칸 방문 처리
        visited[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (visited[nx][ny] || arr[nx][ny] == 0)
                continue;

            // 목표 지점에서
            arr[nx][ny] = arr[x][y] + 1;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = false;
            // 시작점 큐에 넣고 0으로 기록하기
            if (arr[i][j] == 2)
            {
                q.push({i, j});
                arr[i][j] = 0;
            }
        }
    }
    bfs();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // 못가는 영역은
            // 방문하지 않았으면서 값이 1인곳
            // 따라서 -1을 출력함.
            if (!visited[i][j] && arr[i][j] == 1)
            {
                cout << -1 << " ";
                continue;
            }
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}