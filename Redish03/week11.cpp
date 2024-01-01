#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int arr[8][8];
int arr2[8][8];
bool visited[8][8];
int wall_count = 3;
queue<pair<int, int>> q_init;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int answer = -1;

void bfs()
{
    queue<pair<int, int>> q;
    q = q_init;
    // arr2 배열에 arr 배열 대입
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr2[i][j] = arr[i][j];
        }
    }

    // BFS 실행
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= N || ny >= M || nx < 0 || ny < 0)
                continue;
            if (visited[nx][ny])
                continue;
            if (arr2[nx][ny] == 1)
                continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            arr2[nx][ny] = 2;
        }
    }
    // visited 초기화
    memset(visited, false, sizeof(visited));

    // 최대 0의 개수 계산
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr2[i][j] == 0)
                tmp++;
        }
    }

    if (tmp > answer)
    {
        answer = tmp;
    }
}

void stand_wall()
{
    // 만약 3개를 다 세웠다면
    if (wall_count == 0)
    {
        // bfs를 돌리고 return
        return bfs();
    }

    // 3개를 다 세우지 않았다면
    // 모든 경우에 대해서 벽을 세우기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // 해당 배열의 값이 0이 아니라면 넘김
            if (arr[i][j] != 0)
                continue;
            // 0일 때 해당 위치에 벽을 세우고 재귀함수 호출
            arr[i][j] = 1;
            wall_count--;
            stand_wall();
            // 돌리고 난 후 wall_count와 배열 값 복구 시킴
            wall_count++;
            arr[i][j] = 0;
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
            if (arr[i][j] == 2)
            {
                q_init.push({i, j});
            }
        }
    }
    stand_wall();
    cout << answer;
}