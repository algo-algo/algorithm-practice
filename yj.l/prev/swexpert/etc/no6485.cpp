//#include<iostream>
//#include<vector>
//
//using namespace std;
//int sums[5001];
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
//        for (int & i : sums) i = 0;
//
//        int N, P;
//        int A, B, C;
//        cin >> N;
//        for (int i = 0; i < N; ++i) {
//            cin >> A >> B;
//
//            for (int j = A; j <= B; ++j) sums[j]++;
//        }
//
//        cin >> P;
//
//        cout << "#" << test_case;
//        for (int i = 0; i < P; ++i) {
//            cin >> C;
//            cout << ' ' << sums[C];
//        }
//        cout << '\n';
//    }
//    return 0;
//}