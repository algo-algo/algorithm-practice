//#include<iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int orders[100001];
//
//vector<int> solution(string checkMap) {
//    vector<int> answer;
//    int state = 0, num = 0, size = 0;
//
//    vector<int> tmp;
//    for (char ch: checkMap) {
//        switch (ch) {
//        case '{':
//            tmp.clear();
//            state = 0;
//            break;
//        case ',':
//            tmp.push_back(num);
//            state = 0;
//            break;
//        case '}':
//            if (!num) break;
//            tmp.push_back(num);
//            state = -1;
//            if (tmp.size() > size) size = tmp.size();
//            for (int n: tmp) {
//                if (orders[n] == 0 || orders[n] > tmp.size()) orders[n] = tmp.size();
//            }
//            tmp.clear();
//            num = 0;
//            break;
//        default:
//            if (state == 0) num = ch - '0';
//            else if (state == 1) {
//                num *= 10;
//                num += ch - '0';
//            }
//            state = 1;
//            break;
//        }
//    }
//
//    for (int i = 0; i < size; ++i) answer.push_back(0);
//    for (int i = 0; i < 100000; i++) {
//        if (orders[i]) answer[orders[i] - 1] = i;
//    }
//    return answer;
//}
//
//int main() {
//    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
//    return 0;
//}