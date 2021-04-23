#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int getResult() {
    int n;
    cin >> n;
    int size = n * 2 + 2;
    vector<vector<int>> adj(size);
    vector<vector<int>> count(size, vector<int>(size));
    vector<vector<int>> cost(size, vector<int>(size));
    int a, b, val;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> val;
        b += n;
        adj[a].push_back(b);
        adj[b].push_back(a);
        count[a][b] = 1;
        cost[a][b] = val;
        cost[b][a] = -val;
    }

    for (int i = 1; i <= n; ++i) {
        adj[0].push_back(i);
        adj[n + i].push_back(size - 1);
        count[0][i] = 1;
        count[n + i][size - 1] = 1;
    }

    int answer = 0;
    while (true) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> prev(size, -1);
        vector<int> dist(size, 5000001);
        vector<bool> check(size, false);

        for (auto dest: adj[0]) {
            if (!count[0][dest]) continue;
            pq.push({0, dest});
            dist[dest] = prev[dest] = 0;
        }

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (p.second == size - 1) break;

            if (check[p.second]) continue;
            check[p.second] = true;

            for (auto dest: adj[p.second]) {
                if (!count[p.second][dest]) continue;
                int d = p.first + cost[p.second][dest];
                if (dist[dest] > d) {
                    pq.push({d, dest});
                    prev[dest] = p.second;
                    check[dest] = false;
                    dist[dest] = d;
                }
            }
        }

        if (prev[size - 1] == -1) break;

        for (int i = size - 1; prev[i] != -1; i = prev[i]) {
            count[prev[i]][i]--;
            count[i][prev[i]]++;
            answer += cost[prev[i]][i];
        }
    }

    return answer;
}

//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    cout << getResult() << ' ';
//    cout << '\n';
//    return 0;
//}