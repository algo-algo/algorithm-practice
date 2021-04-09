//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//
//using namespace std;
//int check[50001];
//
//class Data {
//public:
//    int a, b;
//    bool rel;
//    Data(int a, int b, int relation) { this->a = a; this->b = b; rel = relation == 1; }
//};
//
//int getMinSum(const vector<int>& vec, int sum, int idx) {
//    if (idx == vec.size()) return sum;
//    int plus = getMinSum(vec, sum + vec[idx], idx + 1);
//    int minus = getMinSum(vec, sum - vec[idx], idx + 1);
//    return min(plus > 0 ? plus : -plus, minus > 0 ? minus : -minus);
//}
//
//int find(int x, bool rel) {
//    if (x < 0) {
//        x = -x;
//        rel = !rel;
//    }
//    if (check[x] == x || check[x] == -1) return rel ? x : -x;
////    else return check[x] = find(check[x]);
//    else return find(check[x], rel);
//}
//
//int getResult(vector<Data>& data, int n, int m) {
//    for (auto& item: data) {
//        int &a = item.a, &b = item.b;
//        int aFound = find(a, true), bFound = find(b, true);
//        if (check[a] == 0 && check[b] == 0) {
//            check[a] = a;
//            check[b] = item.rel ? a : -a;
//        }
//        else if (check[a] == 0) {
//            check[a] = item.rel ? bFound : -bFound;
//        }
//        else if (check[b] == 0) {
//            check[b] = item.rel ? aFound : -aFound;
//        }
//        else if (aFound == bFound || aFound == -bFound) {
//            if (aFound != (item.rel ? bFound : -bFound)) return -1;
//        }
//        else {
//            check[bFound > 0 ? bFound : -bFound] = (item.rel ? aFound : -aFound) * (bFound > 0 ? 1 : -1);
//        }
//    }
//
//    int ungrouped = 0;
//    map<int, int> diffMap;
//    for (int i = 1; i <= n; ++i) {
//        if (check[i] == -1) {
//            ungrouped++;
//            continue;
//        }
//        int found = find(i, true);
//        int abs = found > 0 ? found : -found;
//        diffMap[abs] += found > 0 ? 1 : -1;
//    }
//
//    vector<int> diffs;
//    for (auto& item: diffMap) {
//        if (item.second == 0) continue;
//        diffs.push_back(item.second > 0 ? item.second : -item.second);
//    }
//
//    int result = getMinSum(diffs, 0, 0);
//    if (result - ungrouped <= 1) return n % 2;
//    else return result - ungrouped;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    for (int i = 0; i < 5; ++i) {
//        int n, m, a, b, rel;
//        vector<Data> data;
//        cin >> n >> m;
//        for (int j = 0; j < m; ++j) {
//            cin >> rel >> a >> b;
//            data.push_back({a, b, rel});
//        }
//
//        for (int j = 1; j <= n; j++) check[j] = 0;
//
//        cout << getResult(data, n, m);
//        cout << '\n';
//    }
//    return 0;
//}