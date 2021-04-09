//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//vector<int> getResult(const vector<vector<pair<int, int>>>& adj, int n, int k) {
//    vector<vector<int>> fPath(n, vector<int>());
//    fPath[0].push_back(0);
//
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    for (auto& edge : adj[0]) {
//        pq.push({edge.first, edge.second});
//    }
//
//    while (!pq.empty()) {
//        auto p = pq.top();
//        pq.pop();
//
//        if (fPath[p.second].size() >= k) continue;
//        fPath[p.second].push_back(p.first);
//
//        for (auto& edge : adj[p.second]) {
//            pq.push({p.first + edge.first, edge.second});
//        }
//    }
//
//    vector<int> result;
//    for (int i = 0; i < n; ++i) {
//        if (fPath[i].size() < k) result.push_back(-1);
//        else result.push_back(fPath[i][k - 1]);
//    }
//    return result;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
//    int a, b, c;
//    for (int i = 0; i < m; ++i) {
//        cin >> a >> b >> c;
//        adj[a - 1].push_back({c, b - 1});
//    }
//
//    for (auto& item : getResult(adj, n, k))
//        cout << item << '\n';
//    return 0;
//}