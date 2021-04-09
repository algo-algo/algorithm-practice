//#include<iostream>
//#include <string>
//#include <vector>
//#include <sums>
//#include <set>
//
//using namespace std;
//
//void insert(int val, set<int, greater<>>& checkMap, sums<int, int>& m) {
//    auto it = m.find(val);
//    if (it == m.end()) {
//        checkMap.insert(val);
//        m.insert({val, 1});
//    }
//    else if (it->second == 0) {
//        checkMap.insert(val);
//        it->second++;
//    }
//    else it->second++;
//}
//
//void remove(int val, set<int, greater<>>& checkMap, sums<int, int>& m) {
//    auto it = m.find(val);
//    it->second--;
//    if (it->second == 0) checkMap.erase(val);
//}
//
//int solution(vector<int> stones, int k) {
//    int answer = 200000001, idx;
//    set<int, greater<>> checkMap;
//    sums<int, int> m;
//
//    for (idx = 0; idx < k; ++idx) {
//        insert(stones[idx], checkMap, m);
//    }
//    answer = *checkMap.begin();
//
//    for (; idx < stones.size(); ++idx) {
//        remove(stones[idx - k], checkMap, m);
//        insert(stones[idx], checkMap, m);
//        if (*checkMap.begin() < answer) answer = *checkMap.begin();
//    }
//
//    return answer;
//}
//
//int main() {
//    vector<int> stones;
//    stones.push_back(2);
//    stones.push_back(4);
//    stones.push_back(5);
//    stones.push_back(3);
//    stones.push_back(2);
//    stones.push_back(1);
//    stones.push_back(4);
//    stones.push_back(2);
//    stones.push_back(5);
//    stones.push_back(1);
//    solution(stones, 3);
//    return 0;
//}