//#include<iostream>
//#include<queue>
//
//using namespace std;
//unsigned char sums[100][100];
//bool result[100][100];
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//
//class Point {
//public:
//    int x;
//    int y;
//    int value;
//    Point(int x, int y, int oldValue) {
//        this->x = x;
//        this->y = y;
//        this->value = oldValue + sums[x][y];
//    }
//    bool operator<(const Point& p) const {
//        return value > p.value;
//    }
//    bool operator==(const Point& p) const {
//        return x == p.x && y == p.y;
//    }
//};
//
//bool isValid(int x, int y, const int size) {
//    if (x < 0 || y < 0 || x >= size || y >= size) return false;
//    return true;
//}
//
//int getResult(int size) {
//    priority_queue<Point> pq;
//    Point zero(0, 0, 0);
//    pq.push(zero);
//    result[0][0] = true;
//
//    while(!pq.empty()) {
//        Point p = pq.top();
//        pq.pop();
//        if (p.x == size -1 && p.y == size -1) {
//            return p.value;
//        }
//
//        for (int i = 0; i < 4; i++) {
//            int newX = p.x + dx[i];
//            int newY = p.y + dy[i];
//            if (!isValid(newX, newY, size)) continue;
//            Point np(newX, newY, p.value);
//
//            if (!result[newX][newY]){
//                pq.push(np);
//                result[newX][newY] = true;
//            }
//        }
//
//    }
//    return -1;
//}
//
//void init() {
//    for (int i = 0; i < 100; i++) {
//        for (int j = 0; j < 100; j++) {
//            sums[i][j] = 0;
//            result[i][j] = false;
//        }
//    }
//}
//
//int main(int argc, char **argv) {
//    cin.tie(NULL);
//    cout.tie(NULL);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin >> T;
//
//    for (test_case = 1; test_case <= T; ++test_case) {
//        init();
//
//        int size;
//        cin >> size;
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                cin >> sums[i][j];
//                sums[i][j] -= '0';
//            }
//        }
//
//        int result = getResult(size);
//        cout << "#" << test_case << " " << result << '\n';
//    }
//    return 0;
//}

//#include<iostream>
//#include<deque>
//#include<algorithm>
//
//using namespace std;
//unsigned char sums[100][100];
//bool result[100][100];
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//
//class Point {
//public:
//    int x;
//    int y;
//    int value;
//    Point(int x, int y, int oldValue) {
//        this->x = x;
//        this->y = y;
//        this->value = oldValue + sums[x][y];
//    }
//    bool operator<(const Point& p) const {
//        return value < p.value;
//    }
//    bool operator==(const Point& p) const {
//        return x == p.x && y == p.y;
//    }
//};
//
//bool isValid(int x, int y, int size) {
//    if (x < 0 || y < 0 || x >= size || y >= size) return false;
//    return true;
//}
//
//int getResult(int size) {
//    deque<Point> sortedList;
//
//    Point zero(0, 0, 0);
//    sortedList.push_front(zero);
//    result[0][0] = true;
//
//    while (!sortedList.empty()) {
//        Point p = sortedList.front();
//        sortedList.pop_front();
//
//        for (int i = 0; i < 4; i++) {
//            int axisX = p.x + dx[i];
//            int axisY = p.y + dy[i];
//            if (!isValid(axisX, axisY, size)) continue;
//            Point np(axisX, axisY, p.value);
//
//            if (result[axisX][axisY]) { // checked
//                auto it = find(sortedList.begin(), sortedList.end(), np);
//                if (it != sortedList.end()) { // found
//                    it->value = it->value < np.value ? it->value : np.value;
//                }
//            }
//            else {
//                if (np.x == size - 1 && np.y == size - 1) {
//                    return np.value;
//                }
//                sortedList.push_back(np);
//                result[axisX][axisY] = true;
//            }
//        }
//        sort(sortedList.begin(), sortedList.end());
//    }
//
//    return -1;
//}
//
//void init() {
//    for (int i = 0; i < 100; i++) {
//        for (int j = 0; j < 100; j++) {
//            sums[i][j] = 0;
//            result[i][j] = false;
//        }
//    }
//}
//
//int main(int argc, char **argv) {
//    cin.tie(NULL);
//    cout.tie(NULL);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin >> T;
//
//    for (test_case = 1; test_case <= T; ++test_case) {
//        init();
//
//        int size;
//        cin >> size;
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                cin >> sums[i][j];
//                sums[i][j] -= '0';
//            }
//        }
//
//        int result = getResult(size);
//        cout << "#" << test_case << " " << result << '\n';
//    }
//    return 0;
//}