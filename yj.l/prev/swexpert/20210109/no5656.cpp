//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
//int N, X, Y;
//
//int getCount(const vector<vector<int>>& curr) {
//    int count = 0;
//    for (const auto& vec: curr) {
//        for (auto item: vec) {
//            if (item > 0) count++;
//        }
//    }
//    return count;
//}
//
//vector<vector<int>> copyMap(const vector<vector<int>>& curr) {
//    vector<vector<int>> vec;
//    for (int i = 0; i < X; ++i) {
//        vec.push_back(vector<int>());
//        for (int j = 0; j < Y; ++j) {
//            vec[i].push_back(curr[i][j]);
//        }
//    }
//    return vec;
//}
//
//void pullBlocks(vector<vector<int>>& curr) {
//    for (int i = 0; i < Y; ++i) {
//        int idx = X - 1;
//        for (int j = X - 1; j >= 0; --j) {
//            if (curr[j][i]) curr[idx--][i] = curr[j][i];
//        }
//        while (idx >= 0) curr[idx--][i] = 0;
//    }
//}
//
//void bombBlocks(int x, int y, vector<vector<int>>& curr) {
//    int val = curr[x][y];
//    curr[x][y] = 0;
//    for (int i = 0; i < 4; ++i) {
//        int nx = x, ny = y;
//        for (int j = 1; j < val; ++j) {
//            nx += dx[i];
//            ny += dy[i];
//            if (nx < 0 || ny < 0 || nx >= X || ny >= Y) break;
//            bombBlocks(nx, ny, curr);
//        }
//    }
//}
//
//int dfs(int depth, const vector<vector<int>>& currMap) {
//    if (depth == N) {
//        return getCount(currMap);
//    }
//
//    int minSum = 300;
//    for (int i = 0; i < Y; ++i) {
//        int height = 0;
//        while (height < X && currMap[height][i] == 0) height++;
//        if (height == X) continue;
//
//        auto newMap = copyMap(currMap);
//        bombBlocks(height, i, newMap);
//        pullBlocks(newMap);
//        minSum = min(minSum, dfs(depth + 1, newMap));
//    }
//    return minSum == 300 ? 0 : minSum;
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
//        int tmp;
//        cin >> N >> Y >> X;
//        vector<vector<int>> vec;
//
//        for (int i = 0; i < X; ++i) {
//            vec.push_back(vector<int>());
//            for (int j = 0; j < Y; ++j) {
//                cin >> tmp;
//                vec[i].push_back(tmp);
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << dfs(0, vec);
//        cout << '\n';
//    }
//    return 0;
//}