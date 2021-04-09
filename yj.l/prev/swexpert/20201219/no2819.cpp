// #include<iostream>

// using namespace std;
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// int sums[4][4];
// int result[10000000];

// int dfs(int x, int y, int depth, int sum, const int t) {
//     if (x < 0 || x >= 4 || y < 0 || y >= 4) return 0;
//     if (depth > 7) return 0;
//     else if (depth == 7) {
//         if (result[sum] == t) return 0;
//         result[sum] = t;
//         return 1;
//     }

//     int num = sums[x][y];
//     for (int i = 0; i < depth; i++) num *= 10;

//     int result = 0;
//     for (int i = 0; i < 4; i++) {
//         result += dfs(x + dx[i], y + dy[i], depth + 1, sum + num, t);
//     }
//     return result;
// }

// int getResult(int t) {
//     int count = 0;
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++)
//         {
//             count += dfs(i, j, 0, 0, t);
//         }
//     }
//     return count;
// }

// int main(int argc, char** argv)
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int test_case;
//     int T;
//     cin>>T;

//     for(test_case = 1; test_case <= T; ++test_case)
//     {
//         for (int i = 0; i < 4; i++) {
//             for (int j = 0; j < 4; j++)
//             {
//                 cin >> sums[i][j];
//             }
//         }

//         cout << "#" << test_case << ' ';
//         cout << getResult(test_case);
//         cout << '\n';
//     }
//     return 0;
// }