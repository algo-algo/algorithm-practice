//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class Solution {
//    int goal[52];
//    int curr[52];
//    bool isDone() {
//        for (int i = 0; i < 52; ++i)
//            if (curr[i] < goal[i]) return false;
//        return true;
//    }
//    int getNum(char ch) {
//        if (ch <= 'Z') return ch - 'A';
//        return ch - 'a' + 26;
//    }
//public:
//    string minWindow(string s, string t) {
//        for (int i = 0; i < 52; i++) goal[i] = curr[i] = 0;
//        for (char ch: t) goal[getNum(ch)]++;
//
//        int head = 0, tail = 0, len = 100001;
//        string answer;
//        bool done = false;
//        while (true) {
//            if (done) {
//                if (head - tail < len) {
//                    answer = s.substr(tail, head - tail);
//                    len = head - tail;
//                }
//                int c = getNum(s[tail++]);
//                done = --curr[c] >= goal[c];
//            }
//            else {
//                if (head >= s.length()) break;
//                curr[getNum(s[head++])]++;
//                done = isDone();
//            }
//        }
//
//        return answer;
//    }
//};
//
//int main() {
//    Solution s;
//    cout << s.minWindow("a", "aa") << endl;
//}