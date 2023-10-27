#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        int count = 0;
        while (progresses[i] < 100)
        {
            progresses[i] += speeds[i];
            count++;
        }
        q.push(count);
    }

    for (int i = 0; !q.empty(); i++)
    {
        int count = 1;
        int cmp = q.front();
        q.pop();
        while (cmp >= q.front() && !q.empty())
        {
            count++;
            q.pop();
        }
        answer.push_back(count);
    }

    return answer;
}