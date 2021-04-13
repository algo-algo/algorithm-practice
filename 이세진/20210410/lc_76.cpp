//#include <iostream>
//#include <map>
//
//using namespace std;
//
//map<char, int> m;
//
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        int min = 100000, e, st, cnt = 0;
//        string ans;
//        for (int i = 0; i < s.size(); i++) {
//            for (int j = 0; j < t.size(); j++) {
//                if (s[i] == t[j])
//                    m.insert(pair<char, int>(t[j], cnt));
//            }
//        }
//        for (auto iter = m.begin(); iter != m.end(); iter++) {
//
//        }
//
//        return ans = s.substr(st, e - st + 1);
//    }
//};
//
//int main() {
//    Solution so;
//    string s = "ADOBECODEBANC", t = "ABC";
//    so.minWindow(s, t);
//}