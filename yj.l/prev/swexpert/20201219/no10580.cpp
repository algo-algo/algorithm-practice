// #include<iostream>
// #include<algorithm>
// #include<vector>

// using namespace std;
// int b100[100];
// bool b[10000];

// int checkNGetCross(int h) {
//     int count = 0;
//     int h100 = h / 100;
//     int hDv = h100 * 100;

//     b[h] = true;
//     b100[h100]++;

//     for (int i = h % 100 + 1; i < 100; i++) {
//         count += b[hDv + i];
//     }
//     for (int i = h100 + 1; i < 100; i++) {
//         count += b100[i];
//     }

//     return count;
// }

// int getCrossCount(vector<pair<int, int>> sums) {
//     sort(sums.begin(), sums.end());

//     for (int i = 0; i < 10000; i++) b[i] = false;
//     for (int i = 0; i < 100; i++) b100[i] = 0;

//     int cross = 0;
//     for (pair<int, int> pair : sums) {
//         cross += checkNGetCross(pair.second);
//     }

//     return cross;
// }

// int main(int argc, char** argv)
// {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;

//    for(test_case = 1; test_case <= T; ++test_case) {

//        int N, a, b;
//        cin >> N;
//        vector<pair<int, int>> sums;
//        for (int i = 0; i < N; i++) {
//            cin >> a >> b;
//            sums.push_back({a - 1, b - 1});
//        }

//        cout << "#" << test_case << ' ';
//        cout << getCrossCount(sums);
//        cout << '\n';
//    }
//    return 0;
// }