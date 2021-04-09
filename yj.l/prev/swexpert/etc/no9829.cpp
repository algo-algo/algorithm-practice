//#include<iostream>
//
//using namespace std;
//int nums[100];
//bool result[100];
//
//void initCheck() {
//    for (bool & i : result) {
//        i = true;
//    }
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(NULL);
//    cout.tie(NULL);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int L, S;
//        cin >> L >> S;
//
//        initCheck();
//        for (int i = 0; i < S; i++) {
//            int cntZero = 0;
//            for (int j = 0; j < L; j++) {
//                cin >> nums[j];
//                if (nums[j] == 0) cntZero++;
//            }
//
//            int less = cntZero > L / 2 ? 1 : 0;
//            for (int j = 0; j < L; j++) {
//                if (nums[j] == less) result[j] = false;
//            }
//        }
//
//        int result;
//        for (result = 0; result < L; result++) {
//            if (result[result]) break;
//        }
//
//        cout << "#" << test_case << " " << ++result << '\n';
//    }
//    return 0;
//}