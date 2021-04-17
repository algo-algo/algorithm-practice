//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class Record {
//public:
//    int s, e, cnt;
//    Record(int s, int e, int cnt) : s(s), e(e), cnt(cnt) {}
//    int diff(vector<int>& hamsters) {
//        int sum = 0;
//        for (int i = s; i <= e; ++i) sum += hamsters[i];
//        return cnt - sum;
//    }
//};
//
//void combination(vector<vector<int>>& vec, vector<int>& cur, int idx, int end, vector<bool>& check, int d, int md, int x) {
//    if (d == md) {
//        vec.push_back(cur);
//        return;
//    }
//
//    for (int i = idx; i <= end; ++i) {
//        if (check[i]) continue;
//        vector<int> tmp(cur);
//        if (++tmp[i] > x) continue;
//        combination(vec, tmp, i, end, check, d + 1, md, x);
//    }
//}
//
//void dfs(vector<vector<int>>& result, vector<int>& hamsters, int x, vector<Record>& records, int idx, vector<bool>& check) {
//    if (idx == records.size()) {
//        if (!hamsters.empty()) {
//            for (int i = 0; i < hamsters.size(); ++i)
//                if (!check[i]) hamsters[i] = x;
//            result.push_back(hamsters);
//        }
//        return;
//    }
//
//    auto& record = records[idx];
//    int diff = record.diff(hamsters);
//    if (diff < 0) return;
//
//    vector<vector<int>> comb;
//    combination(comb, hamsters, record.s, record.e, check, record.cnt - diff, record.cnt, x);
//    vector<bool> tmpCheck(check);
//    for (int i = record.s; i <= record.e; i++) tmpCheck[i] = true;
//    for (auto vec: comb) {
//        dfs(result, vec, x, records, idx + 1, tmpCheck);
//    }
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int n, m, x;
//        cin >> n >> x >> m;
//        vector<Record> records;
//        for (int i = 0; i < m; ++i) {
//            int s, e, cnt;
//            cin >> s >> e >> cnt;
//            records.push_back({s - 1, e - 1, cnt});
//        }
//
//        cout << "#" << test_case << ' ';
//
//        vector<int> hamsters(n);
//        vector<bool> check(n);
//        vector<vector<int>> result;
//        dfs(result, hamsters, x, records, 0, check);
//        if (result.empty()) cout << -1;
//        else {
//            int cnt = 0;
//            vector<int> tmp(n);
//            for (auto& item: result) {
//                int sum = 0;
//                for (int& i: item) sum += i;
//                if (sum > cnt) {
//                    tmp = item;
//                    cnt = sum;
//                }
//                else if (sum == cnt) {
//                    for (int i = 0; i < n; i++) {
//                        if (item[i] < tmp[i]) {
//                            tmp = item;
//                            break;
//                        }
//                    }
//                }
//            }
//            for (auto& item: tmp) cout << item << ' ';
//        }
//        cout << '\n';
//    }
//    return 0;
//}