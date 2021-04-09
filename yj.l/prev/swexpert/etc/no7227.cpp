//#include<iostream>
//
//using namespace std;
//
//class Point{
//public:
//    int x, y;
//    Point() {};
//};
//
//Point nums[20];
//int sumAllX;
//int sumAllY;
//
//long long dfs(int depth, int maxDepth, int sumX, int sumY, int idx) {
//    if (depth == maxDepth) {
//        long long x = sumAllX - sumX - sumX;
//        long long y = sumAllY - sumY - sumY;
//        return x * x + y * y;
//    }
//    if (idx - depth > maxDepth) {
//        return 9223372036854775807LL;
//    }
//
//    long long min = 9223372036854775807LL;
//    for (int i = idx; i < maxDepth * 2; ++i) {
//        long long result = dfs(depth + 1, maxDepth, sumX + nums[idx].x, sumY + nums[idx].y, i + 1);
//        if (result < min) min = result;
//    }
//    return min;
//}
//
//long long getResult(int size) {
//    sumAllX = 0;
//    sumAllY = 0;
//    for (int i = 0; i < size; ++i) {
//        sumAllX += nums[i].x;
//        sumAllY += nums[i].y;
//    }
//
//    return dfs(0, size / 2, 0, 0, 0);
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
//        int N;
//        cin >> N;
//        for (int i = 0; i < N; i++) {
//            cin >> nums[i].x >> nums[i].y;
//        }
//
//        cout << "#" << test_case << " ";
//        cout << getResult(N);
//        cout << '\n';
//    }
//    return 0;
//}