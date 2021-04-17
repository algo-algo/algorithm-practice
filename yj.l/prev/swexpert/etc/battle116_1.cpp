//#include<iostream>
//
//using namespace std;
//
//int p, q, r;
//int a, b, cnt, d;
//
//char isRed() {
//    bool red = p + r > cnt || p - r < a || q + r > d || q - r < b;
//    return red ? 'Y' : 'N';
//}
//
//char isBlue() {
//    int square = r * r;
//    int x = p - a;
//    int y = q - b;
//    if (x * x + y * y > square) return 'Y';
//
//    x = p - cnt; y = q - b;
//    if (x * x + y * y > square) return 'Y';
//
//    x = p - a; y = q - d;
//    if (x * x + y * y > square) return 'Y';
//
//    x = p - cnt; y = q - d;
//    if (x * x + y * y > square) return 'Y';
//
//    return 'N';
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
//        cout << "#" << test_case << ' ';
//
//        cin >> p >> q >> r;
//        cin >> a >> b >> cnt >> d;
//
//        cout << isRed();
//        cout << isBlue();
//
//        cout << '\n';
//    }
//    return 0;
//}