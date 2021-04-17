//#include<iostream>
//
//using namespace std;
//int rsqaure[10];
//
//int getScore(int distance) {
//    int score = 0;
//    for (int r : rsqaure) {
//        if (distance <= r) score++;
//        else break;
//    }
//    return score;
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
//    for (int i = 0; i < 10; ++i) {
//        rsqaure[i] = (200 - i * 20) * (200 - i * 20);
//    }
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int N, x, y, score = 0;
//        cin >> N;
//        for (int i = 0; i < N; ++i) {
//            cin >> x >> y;
//            score += getScore(x * x + y * y);
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << score;
//        cout << '\n';
//    }
//    return 0;
//}