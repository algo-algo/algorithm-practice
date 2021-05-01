#include<iostream>
#include<vector>

using namespace std;

int dfs(int curr, bool prev, vector<int>& village, vector<int>& dp, vector<bool>& check, vector<vector<int>>& adj) {
    int sum = 0;
    check[curr] = true;
    for (int neighbor: adj[curr]) {
        if (check[neighbor]) continue;
        if (dp[neighbor] != -1) sum += dp[neighbor];
        else {
            sum += dfs(neighbor, false, village, dp, check, adj);
        }
    }

    if (!prev) {
        int sum2 = village[curr];
        for (int neighbor: adj[curr]) {
            if (check[neighbor]) continue;
            sum2 += dfs(neighbor, true, village, dp, check, adj);
        }
        if (sum2 > sum) sum = sum2;
        dp[curr] = sum;
    }
    check[curr] = false;

    return sum;
}

void start() {
    int n, val;
    cin >> n;

    vector<int> village, dp(n, -1);
    vector<bool> check(n, false);
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> val;
        village.push_back(val);
    }
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    cout << dfs(0, false, village, dp, check, adj);
}

int main(int argc, char** argv)
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    start();
    cout << '\n';
    return 0;
}
