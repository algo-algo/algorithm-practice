//#include<iostream>
//#include<queue>
//
//using namespace std;
//int map[1000][1000];
//int remain[1000][1000];
//
//int findAround(int x, int y) {
//    int val = map[x][y];
//
//    for (int i = -1; i <= 1; ++i) {
//        for (int j = -1; j <= 1; ++j) {
//            if (i == 0 && j == 0) continue;
//            if (map[x + i][y + j] == 0) val--;
//            if (val == 0) return 0;
//        }
//    }
//    return val;
//}
//
//void addAroundNode(queue<pair<int, int>>& que, int x, int y) {
//    for (int i = -1; i <= 1; ++i) {
//        for (int j = -1; j <= 1; ++j) {
//            if (i == 0 && j == 0) continue;
//            int& val = remain[x + i][y + j];
//            if (val == 0 || val == 9) continue;
//            if (--val == 0) que.push({x + i, y + j});
//        }
//    }
//}
//
//int getResult(int h, int w) {
//    queue<pair<int, int>> que;
//
//    for (int i = 1; i < h - 1; ++i) {
//        for (int j = 1; j < w - 1; ++j) {
//            if (map[i][j] == 0 || map[i][j] == 9) continue;
//            int val = findAround(i, j);
//            if (val == 0) que.push({i, j});
//            remain[i][j] = val;
//        }
//    }
//
//    int time;
//    for (time = 0; !que.empty(); ++time) {
//        int size = que.size();
//        for (int i = 0; i < size; ++i) {
//            auto pair = que.front();
//            que.pop();
//
//            addAroundNode(que, pair.first, pair.second);
//        }
//    }
//
//    return time;
//}
//
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
//        int h, w;
//        string str;
//        cin >> h >> w;
//        for (int i = 0; i < h; ++i) {
//            cin >> str;
//            for (int j = 0; j < w; ++j) {
//                remain[i][j] = map[i][j] = str[j] == '.' ? 0 : str[j] - '0';
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(h, w);
//        cout << '\n';
//    }
//    return 0;
//}