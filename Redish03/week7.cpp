#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

void delete_min()
{
    if (pq.empty())
    {
        cout << "0\n";
        return;
    }

    int mins = pq.top();
    pq.pop();
    cout << mins << "\n";
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            delete_min();
        }
        else
        {
            pq.push(command);
        }
    }
}