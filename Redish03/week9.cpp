#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

void print_pq(int x)
{
    if (pq.empty())
    {
        cout << "0\n";
        return;
    }
    cout << pq.top() << "\n";
    pq.pop();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            print_pq(x);
        }
        else
        {
            pq.push(x);
        }
    }
}