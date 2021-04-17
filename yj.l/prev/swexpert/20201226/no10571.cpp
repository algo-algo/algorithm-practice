//#include<iostream>
//
//using namespace std;
//int cMax[100], rMax[100];
//int sums[100][100];
//int map2[100][100];
//
//bool validate(int N, int M) {
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < M; ++j) {
//            map2[i][j] = cMax[i] < rMax[j] ? cMax[i] : rMax[j];
//            if (sums[i][j] != map2[i][j]) return false;
//        }
//    }
//    return true;
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
//        int N, M, num;
//        cin >> N >> M;
//
//        for (int i = 0; i < M; ++i) rMax[i] = 0;
//        for (int i = 0; i < N; ++i) {
//            cMax[i] = 0;
//            for (int j = 0; j < M; ++j) {
//                cin >> num;
//                if (num > cMax[i]) cMax[i] = num;
//                if (num > rMax[j]) rMax[j] = num;
//
//                sums[i][j] = num;
//                map2[i][j] = 100;
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << (validate(N, M) ? "YES" : "NO");
//        cout << '\n';
//    }
//    return 0;
//}