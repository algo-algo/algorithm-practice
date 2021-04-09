//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
////    bool isMatchSub(string& s, string& p, vector<bool>& star, int si, int pi, int chCount, int read) {
////        if (pi == p.length()) return si == s.length();
////        if (chCount - read > s.length() - si) return false;
////
////        if (star[pi]) {
////            if (isMatchSub(s, p, star, si, pi + 1, chCount, read)) return true;
////            for (int si2 = si; si2 < s.size(); ++si2) {
////                if (p[pi] != '.' && p[pi] != s[si2]) break;
////                if (isMatchSub(s, p, star, si2 + 1, pi + 1, chCount, read)) return true;
////            }
////            return false;
////        }
////
////        if (p[pi] != '.' && p[pi] != s[si]) return false;
////        return isMatchSub(s, p, star, si + 1, pi + 1, chCount, read + 1);
////    }
////public:
////    bool isMatch(string s, string p) {
////        vector<bool> star;
////        string p2;
////        int count = 0;
////        for (char ch : p) {
////            if (ch == '*') {
////                star[star.size() - 1] = true;
////                count++;
////            }
////            else {
////                star.push_back(false);
////                p2.push_back(ch);
////            }
////        }
////
////        return isMatchSub(s, p2, star, 0, 0, star.size() - count, 0);
////    }
//public:
//    bool isMatch(char c, char p) {
//        return p == '.' || c == p;
//    }
//    bool isMatch(string s, string p) {
//        if (p.length() == 0) return s.length() == 0;
//        string p2;
//        vector<bool> star;
//        for (char ch : p) {
//            if (ch == '*') star[star.size() - 1] = true;
//            else {
//                star.push_back(false);
//                p2.push_back(ch);
//            }
//        }
//
//        vector<vector<bool>> vec(star.size(), vector<bool>(s.size() + 1));
//        for (int i = 0; i < star.size(); ++i) {
//            for (int j = 0; j <= s.size(); ++j) {
//                if (i == 0) {
//                    if (j == 0) vec[i][j] = star[i];
//                    else if (j == 1) vec[i][j] = isMatch(s[j - 1], p2[i]);
//                    else {
//                        vec[i][j] = star[i] && vec[i][j - 1] && isMatch(s[j - 1], p2[i]);
//                        if (!vec[i][j]) break;
//                    }
//                }
//                else {
//                    if (j == 0) {
//                        vec[i][j] = star[i] && vec[i - 1][j];
//                    }
//                    else {
//                        vec[i][j] = star[i] && (vec[i - 1][j] || vec[i][j - 1] && isMatch(s[j - 1], p2[i]))
//                                || !star[i] && vec[i - 1][j - 1] && isMatch(s[j - 1], p2[i]);
//                    }
//                }
//            }
//        }
//
//        return vec[star.size() - 1][s.size()];
//    }
//};
//
//int main() {
//    Solution solution;
//    cout << solution.isMatch("aab", "") << endl;
//    cout << solution.isMatch("aab", "c*a*b") << endl;
//    cout << solution.isMatch("bccbbabcaccacbcacaa", ".*b.*c*.*.*.c*a*.c") << endl;
//
//    return 0;
//}