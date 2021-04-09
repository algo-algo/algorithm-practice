//#include<iostream>
//
//using namespace std;
//
//int getResult(double l, double p, double c) {
//    int expr = 0, result = 0;
//    double d = p / l;
//
//    while (d > 1) {
//        d /= c;
//        expr++;
//    }
//
//    for (int i = 1; i < expr; i *= 2) result++;
//    return result;
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
//        double l, p, c;
//        cin >> l >> p >> c;
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(l, p, c);
//        cout << '\n';
//    }
//    return 0;
//}