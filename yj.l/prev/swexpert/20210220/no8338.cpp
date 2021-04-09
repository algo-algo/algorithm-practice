//#include<iostream>
//
//using namespace std;
//int nums[10];
//
//int dfs(const int & size, int depth, int value) {
//    if (depth == size) return value;
//
//    int valAdd = dfs (size, depth + 1, value + nums[depth]);
//    int valPro = dfs (size, depth + 1, value * nums[depth]);
//    return valAdd > valPro ? valAdd : valPro;
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
//        int n;
//        cin >> n;
//        for (int i = 0; i < n; ++i) {
//            cin >> nums[i];
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << dfs(n, 1, nums[0]);
//        cout << '\n';
//    }
//    return 0;
//}