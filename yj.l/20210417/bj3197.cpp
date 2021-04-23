#include<iostream>
#include<vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

inline bool checkAround(vector<vector<pair<int, int>>>& map, int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[x].size()) continue;
        if (map[nx][ny].first % 2 == 1) return true;
    }
    return false;
}

int unionFind(vector<int>& areaVec, int val) {
    if (areaVec[val] == val) return val;
    else return areaVec[val] = unionFind(areaVec, areaVec[val]);
}

void joinArea(vector<int>& areaVec, int a, int b) {
    a = unionFind(areaVec, a);
    b = unionFind(areaVec, b);

    areaVec[b] = a;
}

void addNewNode(vector<vector<pair<int, int>>>& map, int x, int y, vector<pair<int, int>>& vec, vector<int>& areaVec) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[x].size()) continue;
        if (map[nx][ny].first == 2) {
            vec.push_back({nx, ny});
            map[nx][ny].first = 4;
        }
        if (map[nx][ny].second != 0) {
            if (map[x][y].second == 0) map[x][y].second = map[nx][ny].second;
            else if (map[x][y].second != map[nx][ny].second
                && unionFind(areaVec, map[nx][ny].second) != unionFind(areaVec, map[x][y].second))
                    joinArea(areaVec, map[nx][ny].second, map[x][y].second);
        }
    }
}

void setAreaDfs(vector<vector<pair<int, int>>>& map, int x, int y, int num, vector<int>& lVec) {
    map[x][y].second = num;
    if (map[x][y].first == 3) lVec.push_back(num);
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[x].size()) continue;
        if (map[nx][ny].first % 2 == 0 || map[nx][ny].second != 0) continue;
        setAreaDfs(map, nx, ny, num, lVec);
    }
}

int getResult(vector<vector<pair<int, int>>>& map) {
    vector<pair<int, int>> que;
    vector<int> areaVec(1);
    vector<int> lVec;

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            auto& p = map[i][j];
            if (p.first == 2) {
                if (checkAround(map, i, j)) {
                    que.push_back({i, j});
                    p.first = 4;
                }
            }
            else {
                if (p.second == 0) {
                    int num = areaVec.size();
                    setAreaDfs(map, i, j, num, lVec);
                    areaVec.push_back(num);
                }
            }
        }
    }

    if (lVec.size() != 2) return -1;

    int time = 0;
    while (!que.empty()) {
        time++;
        vector<pair<int, int>> tmp;
        for (auto p: que) map[p.first][p.second].first = 1;
        for (auto p: que) addNewNode(map, p.first, p.second, tmp, areaVec);

        if (unionFind(areaVec, lVec[0]) == unionFind(areaVec, lVec[1])) return time;
        tmp.swap(que);
    }
    return -1;
}

//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int r, c;
//    cin >> c >> r;
//    vector<vector<pair<int, int>>> map(c, vector<pair<int, int>>(r));
//    char ch;
//    for (int i = 0; i < c; ++i) {
//        for (int j = 0; j < r; ++j) {
//            cin >> ch;
//            if (ch == '.') map[i][j].first = 1;
//            else if (ch == 'X') map[i][j].first = 2;
//            else if (ch == 'L') map[i][j].first = 3;
//        }
//    }
//
//    cout << getResult(map) << ' ';
//    cout << '\n';
//    return 0;
//}