//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//int getCost(int tmp, int val) {
//    if (tmp != 0) return tmp > 0 ? 1 : -1;
//    return val > 0 ? 1 : 0;
//}
//
//int getResult(vector<vector<int>>& adj, vector<vector<int>>& map, vector<int>& goal, vector<int>& curr) {
//    int size = goal.size() + 2;
//    vector<int> diff1, diff2;
//    for (int i = 0; i < size - 2; ++i) {
//        if (goal[i] != curr[i]) {
//            goal[i] ? diff1.push_back(i + 1) : diff2.push_back(i + 1);
//        }
//    }
//
//    vector<vector<int>> use(size, vector<int>(size));
//    for (int black: diff1) {
//        adj[0].push_back(black);
//        adj[black].push_back(0);
//        use[0][black] = 1;
//    }
//
//    for (int white: diff2) {
//        adj[white].push_back(size - 1);
//        adj[size - 1].push_back(white);
//        use[white][size - 1] = 1;
//    }
//
//    int answer = 0;
//    while (true) {
//        vector<int> dist(size, size), prev(size, -1);
//        vector<bool> check(size, false);
//        queue<int> que;
//
//        que.push(0);
//        dist[0] = 0;
//        check[0] = true;
//
//        while (!que.empty()) {
//            int p = que.front();
//            que.pop();
//            check[p] = false;
//
//            for (const int& n: adj[p]) {
//                int cost = getCost(use[p][n], map[p][n]);
//                if (cost != 0 && dist[p] + cost < dist[n]) {
//                    dist[n] = dist[p] + cost;
//                    prev[n] = p;
//                    if (!check[n]) {
//                        que.push(n);
//                        check[n] = true;
//                    }
//                }
//            }
//        }
//
//        if (prev[size - 1] == -1) break;
//
//        for (int i = size - 1; i != 0; i = prev[i]) {
//            if (map[prev[i]][i] != 0) {
//                if (use[prev[i]][i] == 0) use[i][prev[i]]--;
//                else use[prev[i]][i]++;
//            }
//            else {
//                use[i][prev[i]] = -use[prev[i]][i];
//                use[prev[i]][i] = 0;
//            }
//        }
//        answer += dist[size - 1] - 2;
//    }
//
//    return answer;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int T;
//    cin >> T;
//    for (int testCase = 0; testCase < T; ++testCase) {
//        int n, m, x, y;
//        cin >> n >> m;
//
//        vector<vector<int>> adj(n + 2, vector<int>());
//        vector<vector<int>> map(n + 2, vector<int>(n + 2));
//        vector<int> goal(n), curr(n);
//        for (int i = 0; i < m; ++i) {
//            cin >> x >> y;
//            adj[x].push_back(y);
//            adj[y].push_back(x);
//            map[x][y] = map[y][x] = 1;
//        }
//
//        for (int i = 0; i < n; ++i) cin >> goal[i];
//        for (int i = 0; i < n; ++i) cin >> curr[i];
//
//        cout << getResult(adj, map, goal, curr) << '\n';
//    }
//    return 0;
//}