//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int dx[4] = {-1, 1, 0, 0};
//int dy[4] = {0, 0, -1, 1};
//int groupIdx[100][100];
//
//class Group {
//public:
//    int x, y, size, dir;
//    vector<pair<int, int>> candidate;
//    Group(int x, int y, int size, int dir) : x(x), y(y), size(size), dir(dir) {}
//    void joinGroup(const Group& g) {
//        candidate.push_back({g.size, g.dir});
//    }
//    void decideDir() {
//        if (candidate.empty()) return;
//        int maxSize = size;
//        for (auto pair: candidate) {
//            if (pair.first > maxSize) {
//                maxSize = pair.first;
//                dir = pair.second;
//            }
//            size += pair.first;
//        }
//        vector<pair<int, int>>().swap(candidate);
//    }
//    void move(int n) {
//        x += dx[dir];
//        y += dy[dir];
//        if (x == 0 || y == 0 || x == n - 1 || y == n - 1) {
//            size /= 2;
//            dir += dir % 2 == 0 ? 1 : -1;
//        }
//    }
//    bool empty() { return size == 0; }
//};
//
//void clearIdx() {
//    for (auto & row : groupIdx)
//        for (int & idx : row)
//            idx = -1;
//}
//
//int getResult(vector<Group>& groups, int n, int t) {
//    for (int i = 0; i < t; ++i) {
//        clearIdx();
//
//        for (int j = 0; j < groups.size(); j++) {
//            Group& g = groups[j];
//
//            g.move(n);
//            if (g.empty()) continue;
//
//            if (groupIdx[g.x][g.y] == -1) {
//                groupIdx[g.x][g.y] = j;
//            }
//            else {
//                groups[groupIdx[g.x][g.y]].joinGroup(g);
//                groups.erase(groups.begin() + j--);
//            }
//        }
//
//        for (Group& g: groups) {
//            g.decideDir();
//        }
//    }
//
//    int result = 0;
//    for (auto group: groups) result += group.size;
//    return result;
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
//        clearIdx();
//        int n, t, k, x, y, num, dir;
//        vector<Group> groups;
//        cin >> n >> t >> k;
//
//
//        for (int i = 0; i < k; ++i) {
//            cin >> x >> y >> num >> dir;
//            groups.push_back({x, y, num, dir - 1});
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(groups, n, t);
//        cout << '\n';
//    }
//    return 0;
//}