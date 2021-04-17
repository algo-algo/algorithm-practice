//#include<iostream>
//#include<vector>
//
//using namespace std;
//vector<int> sums[1000];
//int len[1000];
//
//int dfs(int prev, int curr, int depth) {
//    if (len[curr] != -1) return depth - len[curr];
//    len[curr] = depth;
//
//    for (int next: sums[curr]) {
//        if (prev == next) continue;
//        int result = dfs(curr, next, depth + 1);
//        if (result != 0) return result;
//    }
//    return 0;
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
//        int n, n1, n2;
//        cin >> n;
//
//        for (int i = 0; i < n; ++i) vector<int>().swap(sums[i]);
//        for (int i = 0; i < n; ++i) {
//            cin >> n1 >> n2;
//            n1--; n2--;
//            sums[n1].push_back(n2);
//            sums[n2].push_back(n1);
//        }
//        for (auto & item: len) item = -1;
//
//        cout << "#" << test_case << ' ';
//        cout << dfs(-1, 0, 0);
//        cout << '\n';
//    }
//    return 0;
//}