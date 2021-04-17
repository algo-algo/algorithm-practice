//#include<iostream>
//
//using namespace std;
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
//        int N;
//        cin >> N;
//
//        cout << "#" << test_case;
//        int sentence = 0, count = 0;
//        bool end = false, ok;
//        while (sentence < N) {
//            ok = true;
//            string str;
//            cin >> str;
//
//            int len = str.length();
//            if (str[len - 1] == '!' || str[len - 1] == '?' || str[len - 1] == '.') {
//                sentence++;
//                end = true;
//                len--;
//            }
//
//            if (!(str[0] >= 'A' && str[0] <= 'Z')) ok = false;
//
//            for (int i = 1; i < len && ok; ++i) {
//                if (!(str[i] >= 'a' && str[i] <= 'z')) ok = false;
//            }
//
//            if (ok) count++;
//            if (end) {
//                cout << ' ' << count;
//                count = 0;
//                end = false;
//            }
//        }
//        cout << '\n';
//    }
//    return 0;
//}