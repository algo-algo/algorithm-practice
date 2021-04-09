//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<tuple>
//
//using namespace std;
//int kind[200001];
//
//class Node {
//public:
//    int y, cnt;
//    Node(int y, int cnt) { this->y = y; this->cnt = cnt; }
//};
//
//class Row {
//public:
//    int x, p;
//    vector<Node> row;
//    Row(int x, int y, int cnt) { this->x = x; row.push_back({y, cnt}); p = 0; }
//    void insert(int y, int cnt) { row.push_back({y, cnt}); p++; }
//    int getYMax() { if (p == -1) return -1; return row[p].y; }
//    bool remove(int y, int &count) {
//        if (p == -1 || row[p].y < y) return false;
//        count--;
//        if (--kind[row[p--].cnt] == 0) return true;
//        return false;
//    }
//    bool removeAll(int &count) {
//        for (; p >= 0; p--) {
//            count--;
//            if (--kind[row[p].cnt] == 0) { p--; return true; }
//        }
//        return false;
//    }
//    void restore(int &count) {
//        while (++p < row.size()) {
//            kind[row[p].cnt]++;
//            count++;
//        }
//        p--;
//    }
//};
//
//class Map {
//public:
//    vector<Row> sums;
//    void insert(const vector<tuple<int, int, int>>& vec) {
//        int x = 0;
//        Row *rp;
//        for (tuple<int, int, int> tup : vec) {
//            if (get<0>(tup) != x) {
//                rp = new Row(get<0>(tup), get<1>(tup), get<2>(tup));
//                sums.push_back(*rp);
//            }
//            rp->insert(get<1>(tup), get<2>(tup));
//            kind[get<2>(tup)]++;
//        }
//    }
//    void init(int k) {
//        vector<Row> empty;
//        swap(sums, empty);
//        for (int i = 1; i <= k; ++i) kind[i] = 0;
//    }
//    int size() { return sums.size(); }
//};
//
//class MapSearch {
//public:
//    int k, n;
//    Map sums;
//    MapSearch(Map& sums, int k, int n) { this->sums = sums; this->k = k; this->n = n; }
//    int search() {
//        int size = sums.size();
//        int count = n, maxCount = 0;
//        for (int j = size - 1; j > 0; --j) {
//            for (int i = 0; i < j; ++i) {
//                for (int l = i; l <= j; ++l) sums.sums[l].restore(count);
//
//                int yMax = 0;
//                bool done = false;
//                while (yMax != -1 || !done) {
//                    for (int l = i; l <= j; ++l) yMax = max(yMax, sums.sums[l].getYMax());
//                    for (int l = i; l <= j; ++l) done = sums.sums[l].remove(yMax, count);
//                }
//
//            }
//        }
//    }
//};
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
//
//
//        cout << "#" << test_case << ' ';
//
//        cout << '\n';
//    }
//    return 0;
//}