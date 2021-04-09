//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int solution(vector<vector<int>> board, vector<int> moves) {
//    stack<int> st;
//    vector<int> heights;
//    int maxHeight = board.size();
//    int answer = 0;
//
//    for (int i = 0; i < board[0].size(); i++) {
//        int height = 0;
//        while (!board[height][i]) height++;
//        heights.push_back(height);
//    }
//
//    for (int idx: moves) {
//        idx--;
//        if (heights[idx] >= maxHeight) continue;
//
//        int doll = board[heights[idx]][idx];
//        board[heights[idx]++][idx] = 0;
//
//        if (!st.empty() && st.top() == doll) {
//            answer += 2;
//            st.pop();
//        }
//        else st.push(doll);
//    }
//
//    return answer;
//}
//
//int main() {
//    vector<vector<int>> board;
//    vector<int> row, row1, row2, row3, row4, row5, moves;
//    row.push_back(0);row.push_back(0);row.push_back(0);row.push_back(0);row.push_back(0);
//    row1.push_back(0);row1.push_back(0);row1.push_back(0);row1.push_back(0);row1.push_back(0);
//    row2.push_back(0);row2.push_back(0);row2.push_back(1);row2.push_back(0);row2.push_back(3);
//    row3.push_back(0);row3.push_back(2);row3.push_back(5);row3.push_back(0);row3.push_back(1);
//    row4.push_back(4);row4.push_back(2);row4.push_back(4);row4.push_back(4);row4.push_back(2);
//    row5.push_back(3);row5.push_back(5);row5.push_back(1);row5.push_back(3);row5.push_back(1);
//    moves.push_back(1);moves.push_back(5);moves.push_back(3);moves.push_back(5);moves.push_back(1);moves.push_back(2);moves.push_back(1);moves.push_back(4);
//
//    board.push_back(row);
//    board.push_back(row1);
//    board.push_back(row2);
//    board.push_back(row3);
//    board.push_back(row4);
//    board.push_back(row5);
//
//    cout << solution(board, moves) << endl;
//    return 0;
//}