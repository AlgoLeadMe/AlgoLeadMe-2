#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, Dasom;
    int answer = 0;
    // 후보들의 지지자들을 저장할 우선순위 큐 candidator
    priority_queue<int> candidator;

    cin >> N;
    cin >> Dasom;

    for (int i = 0; i < N - 1; i++)
    {
        int voter;
        cin >> voter;
        // 각 후보자의 지지자들을 저장함.
        candidator.push(voter);
    }

    while (!candidator.empty() && candidator.top() >= Dasom)
    {
        // 가장 지지자가 많은 후보자의 지지자수를 얻음
        // 우선순위 큐에 따라 가장 큰 수가 큐의 맨 앞으로 간다.
        int most_candidator = candidator.top();
        // 그 득표자를 빼내고
        candidator.pop();
        // 하나를 뺏은 후
        most_candidator--;
        Dasom++;
        answer++;
        // 뺏은 결과를 다시 후보자에 넣어줌.
        candidator.push(most_candidator);
    }
    cout << answer;
}