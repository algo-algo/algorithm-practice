// 어떠한 행, 열, 그리고 두 대각선 중 하나가 4개의 같은 말을 포함하거나, 3개의 같은 말과 ‘T’ 를 포함하면,
//=> 해당 말의 주인이 이기고 게임이 끝난다.
 
// 그렇지 않은 경우 게임은 계속된다.
 
// 모든 칸이 다 찼는데 게임이 끝나지 않았다면, 동점으로 게임이 끝난다.
 
#include <iostream>
#include <string>
 
using namespace std;
 
string inputStr[4];
 
void InputAndInit()
{
    for (int i = 0; i < 4; i++)
        cin >> inputStr[i];
}
 
string DoProcess() {
    int xcnt, ocnt;
    bool isFinished = true;
    for (int i = 0; i < 4; i++)
    {
        xcnt = 0, ocnt = 0;
        for (int j = 0; j < 4; j++)
        {
            if (inputStr[i][j] == 'O')
                ocnt++;
            else if (inputStr[i][j] == 'X')
                xcnt++;
            else if (inputStr[i][j] == 'T') {
                ocnt++; 
                xcnt++;
            }
            else if(inputStr[i][j] == '.')
                isFinished = false;
        }
        if (ocnt == 4)
            return "O won";
        else if (xcnt == 4)
            return "X won";
    }
 
    for (int j = 0; j < 4; j++)
    {
        xcnt = 0, ocnt = 0;
        for (int i = 0; i < 4; i++)
        {
            //xcnt = 0, ocnt = 0;
            if (inputStr[i][j] == 'O')
                ocnt++;
            else if (inputStr[i][j] == 'X')
                xcnt++;
            else if (inputStr[i][j] == 'T') {
                ocnt++; 
                xcnt++;
            }
        }
        if (ocnt == 4)
            return "O won";
        else if (xcnt == 4)
            return "X won";
    }
 
    xcnt = 0, ocnt = 0;
    for (int i = 0; i < 4; i++) {
        if (inputStr[i][i] == 'O')
            ocnt++;
        else if (inputStr[i][i] == 'X')
            xcnt++;
        else if (inputStr[i][i] == 'T') {
            ocnt++; 
            xcnt++;
        }
    }
    if (ocnt == 4)
        return "O won";
    else if (xcnt == 4)
        return "X won";
 
    xcnt = 0, ocnt = 0;
    for (int i = 0; i < 4; i++) {
        if (inputStr[i][3 - i] == 'O')
            ocnt++;
        else if (inputStr[i][3 - i] == 'X')
            xcnt++;
        else if (inputStr[i][3 - i] == 'T') {
            ocnt++; 
            xcnt++;
        }
    }
    if (ocnt == 4)
        return "O won";
    else if (xcnt == 4)
        return "X won";
 
    if (isFinished)
        return "Draw";
    else
        return "Game has not completed";
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        InputAndInit();
        cout << "#" << test_case << " " << DoProcess() << "\n";
    }
    return 0;
}