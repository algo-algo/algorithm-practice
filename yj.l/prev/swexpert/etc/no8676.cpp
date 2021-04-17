//#include<iostream>
//#include<string>
//
//using namespace std;
//string str;
//const char T[] = "SAMSUNG";
//long long cnt[7];
//const int MOD = 1000000007;
//
//void init() {
//    for (long long & j : cnt) {
//        j = 0;
//    }
//}
//
//long long getResult() {
//    init();
//    int size = str.length();
//    if (size < 7) return 0;
//
//    for (int i = 0; i < size; ++i) {
//        switch (str[i]) {
//            case 'S':
//                cnt[0]++; cnt[0] %= MOD;
//                cnt[3] += cnt[2]; cnt[3] %= MOD; break;
//            case 'A':
//                cnt[1] += cnt[0]; cnt[1] %= MOD; break;
//            case 'M':
//                cnt[2] += cnt[1]; cnt[2] %= MOD; break;
//            case 'U':
//                cnt[4] += cnt[3]; cnt[4] %= MOD; break;
//            case 'N':
//                cnt[5] += cnt[4]; cnt[5] %= MOD; break;
//            case 'G':
//                cnt[6] += cnt[5]; cnt[6] %= MOD; break;
//            default:
//                break;
//        }
//    }
//
//    return cnt[6];
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
//        cin >> str;
//
//        cout << "#" << test_case << " ";
//        cout << getResult();
//        cout << '\n';
//    }
//    return 0;
//}