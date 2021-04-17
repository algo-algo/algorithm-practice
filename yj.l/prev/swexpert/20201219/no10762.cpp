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
//        int N, num, xorSum = 0, sum = 0, min = 1000000;
//        cin >> N;
//        for (int i = 0; i < N; i++) {
//            cin >> num;
//            if (num < min) min = num;
//            sum += num;
//            xorSum ^= num;
//        }
//
//        cout << "#" << test_case << ' ';
//        if (xorSum == 0) cout << sum - min;
//        else cout << "NO";
//        cout << '\n';
//    }
//    return 0;
//}