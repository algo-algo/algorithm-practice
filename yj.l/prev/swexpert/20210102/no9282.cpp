//#include<iostream>
//
//using namespace std;
//int sums[50][50];
//pair<int, int> result[50][50][51][51];
//
//pair<int, int> dfs(int x, int dx, int y, int dy) {
//    if (dx == 1 && dy == 1) return {0, sums[x][y]};
//    if (result[x][y][dx][dy].first != 0) return result[x][y][dx][dy];
//
//    int allCnt = 0;
//    int sum = 2147483647;
//    for (int i = 1; i < dx; ++i) {
//        auto pair1 = dfs(x, i, y, dy);
//        auto pair2 = dfs(x + i, dx - i, y, dy);
//        if (allCnt == 0) allCnt = pair1.second + pair2.second;
//        sum = min(pair1.first + pair2.first + allCnt, sum);
//    }
//    for (int i = 1; i < dy; ++i) {
//        auto pair1 = dfs(x, dx, y, i);
//        auto pair2 = dfs(x, dx, y + i, dy - i);
//        if (allCnt == 0) allCnt = pair1.second + pair2.second;
//        sum = min(pair1.first + pair2.first + allCnt, sum);
//    }
//
//    result[x][y][dx][dy] = {sum, allCnt};
//    return result[x][y][dx][dy];
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
//        int N, M;
//        cin >> N >> M;
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < M; ++j) {
//                cin >> sums[i][j];
//            }
//        }
//
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < M; ++j) {
//                for (int k = 1; k <= N - i; ++k) {
//                    for (int l = 1; l <= M - j; ++l) {
//                        result[i][j][k][l] = {0, 0};
//                    }
//                }
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << dfs(0, N, 0, M).first;
//        cout << '\n';
//    }
//    return 0;
//}