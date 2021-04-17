//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//class Solution {
//public:
//    int countSubstrings(string checkMap) {
//        int count = 0, len = checkMap.length();
//        queue<int> que;
//        for (int i = 0; i < len; ++i) {
//            char ch = checkMap[i];
//            count++;
//            int size = que.size();
//            for (int j = 0; j < size; j++) {
//                int idx = que.front();
//                que.pop();
//                if (i >= idx && checkMap[i - idx] == ch) {
//                    count++;
//                    que.push(idx + 2);
//                }
//            }
//
//            que.push(1);
//            que.push(2);
//        }
//
//        return count;
//    }
//    int countSubstrings1(string checkMap) {
//        int len = checkMap.length();
//        if (len == 0) return 0;
//
//        int count = 0;
//        vector<vector<int>> dp(len, vector<int>(len, 0));
//
//        for (int i=0; i < len; i++) {
//            dp[i][i] = 1;
//        }
//        for (int i = len - 2; i >= 0; i--) {
//            for (int j = i+1; j < len; j++) {
//                if (checkMap[i] == checkMap[j] && i + 1 == j) dp[i][j] = 1;
//                else if (checkMap[i] == checkMap[j]) dp[i][j] = dp[i+1][j-1];
//                else dp[i][j] = 0;
//            }
//        }
//        for (int i = 0; i < len; i++) {
//            for (int j = 0; j < len; j++) {
//                if (dp[i][j] == 1) count++;
//            }
//        }
//        return count;
//    }
//    int countSubstrings2(string checkMap) {
//        int ans = 0;
//        for (int i=0; i<checkMap.size();) {
//            int k = i-1, j = i+1;
//            // count the number of same character
//            while (j < checkMap.size() && checkMap[j] == checkMap[i])
//                j++;
//            // compute number of palindromic substrings with all same character
//            ans += (j-i) * (j-i+1) / 2;
//            // extended palindromic substrings
//            while (k >= 0 && j < checkMap.size() && checkMap[j] == checkMap[k])
//                k--, j++, ans++;
//            // update i to skip the same character
//            i = j;
//        }
//        return ans;
//    }
//};
//
//int main() {
//    Solution solution;
////    solution.countSubstrings("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
//    string str = "abaaabac";
//    cout << solution.countSubstrings(str) << endl;
//    cout << solution.countSubstrings2(str) << endl;
//    return 0;
//}