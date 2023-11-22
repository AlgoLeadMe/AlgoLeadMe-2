#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> mbti;
int T, N;

int getDistance(string first, string second, string third)
{
    int dist_mbti = 0;
    for (int i = 0; i < 4; i++)
    {
        if (first[i] != second[i])
        {
            dist_mbti++;
        }
        if (first[i] != third[i])
        {
            dist_mbti++;
        }
        if (third[i] != second[i])
        {
            dist_mbti++;
        }
    }

    return dist_mbti;
}

void find_mbti()
{
    int answer = 8;

    // 비둘기 집 원리를 이용
    if (N > 32)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < mbti.size(); i++)
    {
        int cur_count = 0;
        string first = mbti[i];
        for (int j = i + 1; j < mbti.size(); j++)
        {
            string second = mbti[j];
            for (int k = j + 1; k < mbti.size(); k++)
            {
                string third = mbti[k];

                cur_count = getDistance(first, second, third);
                answer = min(answer, cur_count);
            }
        }
    }

    cout << answer << endl;
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            string MBTI;
            cin >> MBTI;
            mbti.push_back(MBTI);
        }
        find_mbti();
        mbti.clear();
    }
}