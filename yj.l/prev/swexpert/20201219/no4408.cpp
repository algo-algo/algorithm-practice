// #include<iostream>

// using namespace std;
// int sums[200];

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
//         for (int i = 0; i < 401; i++) sums[i] = 0;

//         int N, a, b, max = 0;
//         cin >> N;

//         for (int i = 0; i < N; i++) {
//             cin >> a >> b;

//             if (a > b) swap(a, b);
//             a--; b--;
//             a /= 2;
//             b /= 2;

//             for (int j = a; j <= b; j++) {
//                 sums[j]++;
//                 if (sums[j] > max) max = sums[j];
//             }
//         }

//         cout << "#" << test_case << ' ';
//         cout << max;
//         cout << '\n';
//     }
//     return 0;
// }