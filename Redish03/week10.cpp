#include <iostream>

using namespace std;

int white_count = 0;
int blue_count = 0;
int arr[129][129];

void divide(int n, int x, int y)
{
    int first = arr[x][y];
    bool flag = false;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (first != arr[i][j])
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
    {
        int half = n / 2;
        divide(half, x, y + half);
        divide(half, x + half, y);
        divide(half, x + half, y + half);
        divide(half, x, y);
    }
    else
    {
        if (first == 0)
            white_count++;
        else
            blue_count++;
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    divide(N, 0, 0);
    cout << white_count << '\n'
         << blue_count;
}