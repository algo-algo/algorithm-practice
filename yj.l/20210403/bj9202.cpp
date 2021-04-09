//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
//int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
//int scores[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
//
//bool dfs(vector<string>& board, string& goal, int depth, int x, int y, vector<bool>& check) {
//    if (depth == goal.length()) return true;
//
//    for (int i = 0; i < 8; ++i) {
//        int nx = x + dx[i], ny = y + dy[i];
//        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
//        if (check[nx * 4 + ny] || board[nx][ny] != goal[depth]) continue;
//        check[nx * 4 + ny] = true;
//        if (dfs(board, goal, depth + 1, nx, ny, check)) return true;
//        check[nx * 4 + ny] = false;
//    }
//    return false;
//}
//
//void getResult(vector<string>& words, vector<vector<string>>& boards) {
//    for (auto board: boards) {
//        int count = 0, score = 0;
//        string maxWord;
//        for (string& word: words) {
//            bool found = false;
//            for (int i = 0; i < 4 && !found; ++i) {
//                for (int j = 0; j < 4 && !found; ++j) {
//                    vector<bool> check(16, false);
//                    if (dfs(board, word, 0, i, j, check)) {
//                        if (word.length() > maxWord.length()
//                        || word.length() == maxWord.length() && word < maxWord)
//                            maxWord = word;
//                        count++;
//                        score += scores[word.length()];
//                        found = true;
//                    }
//                }
//            }
//        }
//        cout << score << " " << maxWord << " " << count << '\n';
//    }
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    vector<string> words;
//    vector<vector<string>> boards;
//
//    int n;
//    string str;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> str;
//        words.push_back(str);
//    }
//
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        vector<string> board;
//        for (int j = 0; j < 4; ++j) {
//            cin >> str;
//            board.push_back(str);
//        }
//        boards.push_back(board);
//    }
//
//    getResult(words, boards);
//    return 0;
//}