//#include<iostream>
//
//using namespace std;
//
//int sums[1000][1000];
//int N, M;
//const int MAX = 2147483646;
//
//int getPrev(int x, int y) {
//    if (x <= 0 && y <= 0) return MAX;
//    if (x <= 0) return sums[x][y - 1];
//    if (y <= 0) return sums[x - 1][y];
//    return sums[x][y - 1] < sums[x - 1][y] ? sums[x][y - 1] : sums[x - 1][y];
//}
//
//int getNext(int x, int y) {
//    if (x >= N - 1 && y >= M - 1) return MAX;
//    if (x >= N - 1) return sums[x][y + 1];
//    if (y >= M - 1) return sums[x + 1][y];
//    return sums[x][y + 1] < sums[x + 1][y] ? sums[x][y + 1] : sums[x + 1][y];
//}
//
//int getResult() {
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < M; ++j) {
//            int tmp = getPrev(i, j) + 1;
//            sums[i][j] = tmp < sums[i][j] ? tmp : sums[i][j];
//        }
//    }
//
//    int result = 0;
//    for (int i = N - 1; i >= 0; --i) {
//        for (int j = M - 1; j >= 0; --j) {
//            int tmp = getNext(i, j) + 1;
//            sums[i][j] = tmp < sums[i][j] ? tmp : sums[i][j];
//            result += sums[i][j];
//        }
//    }
//
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
//        cin >> N >> M;
//
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < M; j++) {
//                char ch;
//                cin >> ch;
//                if (ch == 'W') sums[i][j] = 0;
//                else sums[i][j] = MAX;
//            }
//        }
//
//        int result = getResult();
//
//        cout << "#" << test_case << " ";
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<queue>
//
//using namespace std;
//bool result[1000][1000];
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//
//class Point {
//public:
//    int x, y;
//    Point(int x, int y) {
//        this->x = x; this->y = y;
//    }
//};
//
//bool validate(Point p, const int N, const int M) {
//    if (p.x >= N || p.x < 0 || p.y >= M || p.y < 0) return false;
//    return true;
//}
//
//int getResult(queue<Point> que, const int N, const int M) {
//    int sum = 0, depth = 0;
//    while (!que.empty()) {
//        int count = 0, size = que.size();
//        for (int cnt = 0; cnt < size; ++cnt) {
//            Point p = que.front();
//            que.pop();
//            count++;
//            for (int i = 0; i < 4; ++i) {
//                Point np(p.x + dx[i], p.y + dy[i]);
//                if (!validate(np, N, M)) continue;
//                if (!result[np.x][np.y]){
//                    que.push(np);
//                    result[np.x][np.y] = true;
//                }
//            }
//        }
//        sum += count * depth++;
//    }
//
//    return sum;
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
//        int N, M;
//        cin >> N >> M;
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < M; j++) {
//                result[i][j] = false;
//            }
//        }
//        queue<Point> que;
//
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < M; j++) {
//                char ch;
//                cin >> ch;
//                if (ch == 'W') {
//                    que.push(Point(i, j));
//                    result[i][j] = true;
//                }
//            }
//        }
//
//        int result = getResult(que, N, M);
//
//        cout << "#" << test_case << " ";
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
//}