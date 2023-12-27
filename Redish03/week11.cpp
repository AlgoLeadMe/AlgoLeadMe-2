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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr2[i][j] = arr[i][j];
        }
    }

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

    memset(visited, false, sizeof(visited));

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
    if (wall_count == 0)
    {
        return bfs();
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != 0)
                continue;

            arr[i][j] = 1;
            wall_count--;
            stand_wall();
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