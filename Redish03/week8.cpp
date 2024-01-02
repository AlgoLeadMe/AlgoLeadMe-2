#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int item[101];
vector<pair<int, int>> node[101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int value[101];
int n, m, r;
int answer = 0;

int Dijstra(int idx)
{
    for (int i = 1; i <= n; i++)
    {
        value[i] = 99999999;
    }

    value[idx] = 0;

    pq.push(make_pair(0, idx));

    while (!pq.empty())
    {
        int x = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < node[u].size(); i++)
        {
            int v = node[u][i].first;
            int w = node[u][i].second;

            if (x + w < value[v])
            {
                value[v] = x + w;
                pq.push(make_pair(x + w, v));
            }
        }
    }

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (value[i] <= m)
        {
            sum += item[i];
        }
    }

    return sum;
}

int main()
{
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;

        node[a].push_back(make_pair(b, l));
        node[b].push_back(make_pair(a, l));
    }

    for (int i = 1; i <= n; i++)
    {
        answer = max(answer, Dijstra(i));
    }

    cout << answer;
}