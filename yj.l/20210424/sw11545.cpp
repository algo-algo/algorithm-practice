#include<iostream>
#include<vector>

using namespace std;
void updateState(char ch, int& state) {
    switch (ch) {
        case '.': state = 0; break;
        case 'O': state &= 1; break;
        case 'X': state &= 2; break;
        default: break;
    }
}

int getResult(vector<vector<char>>& board) {
    for (int i = 0; i < 4; ++i) {
        int state = 3;
        for (int j = 0; j < 4; ++j) {
            updateState(board[i][j], state);
        }
        if (state) return state;

        state = 3;
        for (int j = 0; j < 4; ++j) {
            updateState(board[j][i], state);
        }
        if (state) return state;
    }

    int state = 3;
    for (int i = 0; i < 4; ++i) {
        updateState(board[i][i], state);
    }
    if (state) return state;

    state = 3;
    for (int i = 0; i < 4; ++i) {
        updateState(board[i][3 - i], state);
    }
    return state;
}

//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        char ch;
//        vector<vector<char>> board;
//        bool done = true;
//        for (int i = 0; i < 4; ++i) {
//            board.push_back(vector<char>());
//            for (int j = 0; j < 4; ++j) {
//                cin >> ch;
//                if (ch == '.') done = false;
//                board[i].push_back(ch);
//            }
//        }
//        int result = getResult(board);
//        string str;
//        switch (result) {
//            case 1:
//                str = "O won";
//                break;
//            case 2:
//                str = "X won";
//                break;
//            case 0:
//            case 3:
//                str = done ? "Draw" : "Game has not completed";
//                break;
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << str;
//        cout << '\n';
//    }
//    return 0;
//}