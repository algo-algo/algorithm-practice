//#include<iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//bool sums[1<<8];
//
//bool compare(string spare, string str) {
//    if (spare.size() != str.size()) return false;
//    for (int i = 0; i < spare.size(); ++i) {
//        if (spare[i] == '*') continue;
//        if (spare[i] != str[i]) return false;
//    }
//    return true;
//}
//
//int dfs(const vector<string>& user_id, const vector<string>& banned_id, int notCycle, int depth) {
//    if (depth == banned_id.size()) {
//        if (sums[notCycle]) return 0;
//        sums[notCycle] = true;
//        return 1;
//    }
//
//    int result = 0;
//        for (int j = 0; j <user_id.size(); ++j) {
//            if ((1 << j) & notCycle) continue;
//            if (compare(banned_id[depth], user_id[j])) {
//                result += dfs(user_id, banned_id, notCycle + (1 << j), depth + 1);
//            }
//        }
//    return result;
//}
//
//int solution(vector<string> user_id, vector<string> banned_id) {
//    return dfs(user_id, banned_id, 0, 0);
//}
//
//int main() {
//    vector<string> user_id;
//    vector<string> banned_id;
//    user_id.push_back("frodo");user_id.push_back("fradi");user_id.push_back("crodo");user_id.push_back("abc123");user_id.push_back("frodoc");
//    banned_id.push_back("fr*d*");banned_id.push_back("*rodo");banned_id.push_back("******");banned_id.push_back("******");
//    solution(user_id, banned_id);
//    return 0;
//}