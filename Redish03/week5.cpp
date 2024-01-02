#include <iostream>
#include <queue>

using namespace std;

int N, M;
int days = -1;
bool flag = false;
int arr[1001][1001];
int visited[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (visited[nx][ny] != -1)
                continue;
            if (arr[nx][ny] != 0)
                continue;

            q.push(make_pair(nx, ny));
            // visited에 그 칸이 익는 것을 체크한다.
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
}

int main()
{
    // 입력
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = -1;
            if (arr[i][j] == 1)
            {
                q.push(make_pair(i, j));
                visited[i][j]++;
            }
        }
    }

    bfs();

    // 다시 arr과 visited를 훑는다.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // days에 저장된 일이 visited 보다 작거나 같으면 visited를 한다.
            if (days <= visited[i][j])
            {
                days = visited[i][j];
            }

            // 방문하지 않았고, 토마토가 익지 않은 경우 days = -1로 바꿔준다.
            if (arr[i][j] == 0 && visited[i][j] == -1)
            {
                days = -1;
                flag = true;
                break;
            }
        }
        // 토마토가 익지 않은 경우 (0인 경우) days = -1인 상태로 반복문을 탈출한다.
        if (flag)
        {
            break;
        }
    }

    cout << days;
}