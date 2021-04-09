//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//string dfs(string str, int k, int n, int a) {
//    int len = str.length();
//
//    // check repetition
//    for (int i = 1; i * k <= len; ++i) {
//        bool repeating = true;
//        for (int j = 1; j < k; ++j) {
//            if (str.substr(len - i * j, i) != str.substr(len - i * (j + 1), i)) {
//                repeating = false;
//                break;
//            }
//        }
//        if (repeating) return "";
//    }
//
//    if (len == n) return str;
//
//    for (int i = 0; i < a; ++i) {
//        char ch = 'A' + i;
//        string tmp = dfs(str + ch, k, n, a);
//        if (!tmp.empty()) return tmp;
//    }
//    return "";
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int K, N, A;
//    cin >> K >> N >> A;
//
//    string result = dfs("", K, N, A);
//    cout << (result.empty() ? "-1" : result);
//    cout << '\n';
//    return 0;
//}