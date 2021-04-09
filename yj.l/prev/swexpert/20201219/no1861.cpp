// #include<iostream>
//
// using namespace std;
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// pair<int, int> sums[1000][1000];
//
// int dfs(int x, int y, int prev, const int size) {
//     if (x < 0 || x >= size || y < 0 || y >= size) return 0;
//     if (sums[x][y].first != prev + 1) return 0;
//     if (sums[x][y].second != 0) return sums[x][y].second;
//
//     int len = 1;
//     for (int i = 0; i < 4; i++) {
//         len += dfs(x + dx[i], y + dy[i], sums[x][y].first, size);
//     }
//     sums[x][y].second = len;
//     return len;
// }
//
// pair<int, int> getResult(int size) {
//     pair<int, int> result = {-1, 0};
//     for (int i = 0; i < size; i++) {
//         for (int j = 0; j < size; j++) {
//             dfs(i, j, sums[i][j].first - 1, size);
//             if (sums[i][j].second > result.second
//              || sums[i][j].second == result.second && sums[i][j].first < result.first) result = sums[i][j];
//         }
//     }
//
//     return result;
// }
//
// int main(int argc, char** argv)
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int test_case;
//     int T;
//     cin>>T;
//
//     for(test_case = 1; test_case <= T; ++test_case)
//     {
//         int N;
//         cin >> N;
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 cin >> sums[i][j].first;
//                 sums[i][j].second = 0;
//             }
//         }
//
//         pair<int, int> result = getResult(N);
//         cout << "#" << test_case << ' ';
//         cout << result.first << ' ' << result.second;
//         cout << '\n';
//     }
//     return 0;
// }