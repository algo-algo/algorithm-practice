//#include<iostream>
//
//using namespace std;
//
//void start() {
//    int n;
//    cin >> n;
//
//    int prev = 1000000001, val, cntUp = 0, cntDown = 0, answer = 0;
//    bool up = false;
//    for (int i = 0; i < n; ++i) {
//        cin >> val;
//        if (val < prev) {
//            cntDown++;
//            up = false;
//        }
//        else {
//            if (!up) {
//                answer += cntDown * cntUp;
//                cntUp = cntDown = 0;
//                up = true;
//            }
//            cntUp++;
//        }
//        prev = val;
//    }
//    answer += cntDown * cntUp;
//    cout << answer;
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
//    for(test_case = 1; test_case <= T; ++test_case) {
//        cout << "#" << test_case << ' ';
//        start();
//        cout << '\n';
//    }
//    return 0;
//}