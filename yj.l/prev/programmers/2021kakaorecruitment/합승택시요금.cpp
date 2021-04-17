//#include<iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//int map[8][8];
//
//void setFares(int n, int idx) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    for (int i = 1; i <= n; i++) {
//        int& val = map[idx][i];
//        if (val == 0) continue;
//        pq.push({val, i});
//    }
//
//    while (!pq.empty()) {
//        auto pair = pq.top();
//        pq.pop();
//
//        for (int i = 1; i <= n; i++) {
//            if (idx == i) continue;
//            int& val = map[pair.second][i];
//            if (val == 0) continue;
//            if (map[idx][i] == 0 || pair.first + val < map[idx][i]) {
//                map[idx][i] = map[i][idx] = pair.first + val;
//                pq.push({pair.first + val, i});
//            }
//        }
//    }
//}
//
//int solution(int n, int checkMap, int a, int b, vector<vector<int>> fares) {
//    for (auto fare: fares) {
//        map[fare[1]][fare[0]] = map[fare[0]][fare[1]] = fare[2];
//    }
//
//    setFares(n, checkMap);
//    setFares(n, a);
//    setFares(n, b);
//
//    int answer = (map[checkMap][a] < map[checkMap][b] ? map[checkMap][a] : map[checkMap][b]) + map[a][b];
//    if (map[checkMap][b] + map[checkMap][a] < answer) answer = map[checkMap][b] + map[checkMap][a];
//    for (int i = 1; i <= n; i++) {
//        if (map[checkMap][i] == 0 || map[i][a] == 0 || map[i][b] == 0) continue;
//        int val = map[checkMap][i] + map[i][a] + map[i][b];
//        answer = val < answer ? val : answer;
//    }
//
//    return answer;
//}
//
//int main() {
//    vector<vector<int>> vector1{ vector<int>{4, 1, 10}, vector<int>{3, 5, 24}, vector<int>{5, 6, 2}, vector<int>{3, 1, 41}, vector<int>{5, 1, 24}, vector<int>{4, 6, 50}, vector<int>{2, 4, 66}, vector<int>{2, 3, 22}, vector<int>{1, 6, 25} };
//    vector<vector<int>> vector2{ vector<int>{5, 7, 9}, vector<int>{4, 6, 4}, vector<int>{3, 6, 1}, vector<int>{3, 2, 3}, vector<int>{2, 1, 6} };
////    cout << solution(6, 4, 6, 2, vector1) << endl;
//    cout << solution(7, 3, 4, 1, vector2) << endl;
//    return 0;
//}