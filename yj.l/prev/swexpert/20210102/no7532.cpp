//#include<iostream>
//
//using namespace std;
//const int S = 365, E = 24, M = 29;
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
//    int SremM = S % M;
//    int SbyM = S * M;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int checkMap, e, m;
//        cin >> checkMap >> e >> m;
//        checkMap--; e--; m--;
//        int remainder = checkMap % M, cnt1, cnt2;
//
//        for (cnt1 = 0; remainder != m; ++cnt1) {
//            remainder = (remainder + SremM) % M;
//        }
//        remainder = (checkMap + cnt1 * S) % E;
//        for (cnt2 = 0; remainder != e; ++cnt2) {
//            ++remainder %= E;
//        }
//
//        int result = checkMap + cnt1 * S + cnt2 * SbyM + 1;
//        cout << "#" << test_case << ' ';
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
//}