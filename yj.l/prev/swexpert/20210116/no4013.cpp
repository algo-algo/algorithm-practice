//#include<iostream>
//
//using namespace std;
//bool magnet[4][8];
//pair<int, bool> t[20];
//int p[4];
//
//inline int getIdx(int idx, int d) { return (idx + d) % 8; }
//
//void dfs(bool left, bool right, int pIdx, bool d) {
//    if (left && pIdx > 0) {
//        if (magnet[pIdx][getIdx(p[pIdx], 6)] != magnet[pIdx - 1][getIdx(p[pIdx - 1], 2)])
//            dfs(true, false, pIdx - 1, !d);
//    }
//    if (right && pIdx < 3) {
//        if (magnet[pIdx][getIdx(p[pIdx], 2)] != magnet[pIdx + 1][getIdx(p[pIdx + 1], 6)])
//            dfs(false, true, pIdx + 1, !d);
//    }
//
//    if (d) p[pIdx] = getIdx(p[pIdx], 7);
//    else p[pIdx] = getIdx(p[pIdx], 1);
//}
//
//int getResult(int time) {
//    for (int & i : p) i = 0;
//
//    for (int i = 0; i < time; ++i) {
//        dfs(true, true, t[i].first, t[i].second);
//    }
//    int result = 0, tmp = 1;
//    for (int i = 0; i < 4; i++) {
//        if (magnet[i][p[i]]) result += tmp;
//        tmp <<= 1;
//    }
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
//        int k, m1, t1;
//        cin >> k;
//        for (auto & i : magnet)
//            for (bool & j : i)
//                cin >> j;
//        for (int i = 0; i < k; ++i) {
//            cin >> m1 >> t1;
//            t[i] = {m1 - 1, t1 > 0};
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(k);
//        cout << '\n';
//    }
//    return 0;
//}