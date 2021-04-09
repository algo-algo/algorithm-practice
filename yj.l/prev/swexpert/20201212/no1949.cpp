// #include<iostream>

// using namespace std;
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// int result[8][8];
// int sums[8][8];

// int dfs(int x, int y, int length, int prevHeight, int K, const int N) {
//     if (x < 0 || x >= N || y < 0 || y >= N) return 0;
//     if (result[x][y]) return 0;
//     int height = sums[x][y];
//     if (sums[x][y] >= prevHeight) {
//         if (sums[x][y] - K >= prevHeight) return 0;
//         K = 0;
//         height = prevHeight - 1;
//     }
    
//     int maxLen = length;
//     result[x][y] = true;
//     for (int i = 0; i < 4; i++) {
//         int newLen = dfs(x + dx[i], y + dy[i], length + 1, height, K, N);
//         maxLen = newLen > maxLen ? newLen : maxLen;
//     }
//     result[x][y] = false;
//     return maxLen;
// }

// int main(int argc, char** argv)
// {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;

//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int N, K, max = 0;
//        cin >> N >> K;
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                cin >> sums[i][j];
//                if (sums[i][j] > max) max = sums[i][j];
//            }
//        }

//        int result = 0;
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                if (sums[i][j] == max) {
//                    int length = dfs(i, j, 1, 100, K, N);
//                    if (length > result) result = length;
//                }
//            }
//        }

//        cout << "#" << test_case << ' ';
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
// }