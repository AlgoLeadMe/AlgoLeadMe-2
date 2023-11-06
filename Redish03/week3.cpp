#include <string>
#include <vector>
#define LENGTH 3

using namespace std;

// 1. 게임이 완료 된 상황일 때
// 2. O보다 X의 개수가 더 많을 때

int o_count = 0;
int x_count = 0;
bool is_X_win = false;
bool is_O_win = false;

bool check_winner(vector<string> board)
{
    char first_char;

    for (int i = 0; i < LENGTH; i++)
    {
        first_char = board[i][0];

        // 가로 확인
        if (first_char == board[i][1] && first_char == board[i][2])
        {
            if (first_char == 'X')
            {
                is_X_win = true;
            }
            if (first_char == 'O')
            {
                is_O_win = true;
            }
        }
        // 세로 확인
        first_char = board[0][i];
        if (first_char == board[1][i] && first_char == board[2][i])
        {
            if (first_char == 'X')
            {
                is_X_win = true;
            }
            if (first_char == 'O')
            {
                is_O_win = true;
            }
        }
    }

    // 대각선 확인 (왼쪽 위 -> 오른쪽 아래)
    first_char = board[0][0];
    if (first_char == board[1][1] && first_char == board[2][2])
    {
        if (first_char == 'X')
        {
            is_X_win = true;
        }
        if (first_char == 'O')
        {
            is_O_win = true;
        }
    }
    // 대각선 확인 (오른쪽 위 -> 왼쪽 아래)
    first_char = board[0][2];
    if (first_char == board[1][1] && first_char == board[2][0])
    {
        if (first_char == 'X')
        {
            is_X_win = true;
        }
        if (first_char == 'O')
        {
            is_O_win = true;
        }
    }

    if (is_X_win && is_O_win)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool count_OX(vector<string> board)
{
    // X와 O의 개수를 세어준다.
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            if (board[i][j] == 'X')
            {
                x_count++;
            }
            if (board[i][j] == 'O')
            {
                o_count++;
            }
        }
    }

    // 각 경우의 수 확인
    if (x_count > o_count || o_count - x_count > 1)
    {
        return true;
    }
    else if (is_X_win && x_count != o_count)
    {
        return true;
    }
    else if (x_count + o_count == 9 && o_count - x_count != 1)
    {
        return true;
    }
    else if (is_O_win && x_count >= o_count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(vector<string> board)
{
    int answer = 1;

    if (check_winner(board) || count_OX(board))
    {
        answer = 0;
    }

    return answer;
}