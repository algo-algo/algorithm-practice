//#include<iostream>
//#include<vector>
//#include<algorithm>
//#define MAX_SIZE 10000
//
//using namespace std;
//
//class Line {
//public:
//    int a, b, c;
//    Line(int a, int b, int c) { this->a = a; this->b = b; this->c = c; }
//};
//
//class Point {
//public:
//    int x, y, c;
//    Point(int x, int y, int c) : x(x), y(y), c(c) {}
//    bool operator<(const Point &rhs) const {
//        if (x < rhs.x) return true;
//        if (rhs.x < x) return false;
//        return y < rhs.y;
//    }
//    bool operator>(const Point &rhs) const { return rhs < *this; }
//    bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
//};
//
//class Check {
//public:
//    int plus, minus, cnt;
//    Check(int plus, int minus, int cnt) : plus(plus), minus(minus), cnt(cnt) {}
//    Check() { plus = -1; minus = -1; cnt = 0; }
//    void addCnt() { cnt++; }
//    void subCnt() { cnt--; if (!cnt) reset(); }
//    void reset() { plus = -1; minus = -1; }
//};
//
//Check result[MAX_SIZE];
//const Check tmp = {-1, -1, 0};
//
//int getGcd(int a, int b) {
//    int n;
//    if (a < b) swap(a, b);
//    while (b != 0) {
//        n = a % b; a = b; b = n;
//    }
//    return a;
//}
//
//int findDivided(const vector<Line>& lines) {
//    int parallel = 0;
//    vector<Point> vec;
//    for (Line line : lines) {
//        int gcd = getGcd(line.a, line.b);
//        vec.push_back({line.a / gcd, line.b / gcd, 0});
//    }
//    sort(vec.begin(), vec.end());
//
//    int count = lines.size();
//    for (int i = 1; i < count; ++i) {
//        if (vec[i] == vec[i - 1]) parallel++;
//    }
//
//    return count * (count + 1) / 2 + 1 - parallel;
//}
//
//inline bool calculate(Line line, Point point) {
//    return line.a * point.x + line.b * point.y + line.c > 0;
//}
//
//int findPointDivided(const vector<Line>& lines, vector<Point>& points) {
//    int mp = 1, n = points.size();
//    result[0].cnt = n;
//
//    for (Line line : lines) {
//        for (int i = 0; i < n; ++i) {
//            int t;
//            if (calculate(line, points[i])) {
//                if (result[points[i].c].plus == -1) {
//                    result[points[i].c].plus = mp;
//                    ++mp %= MAX_SIZE;
//                }
//                t = result[points[i].c].plus;
//            }
//            else {
//                if (result[points[i].c].minus == -1) {
//                    result[points[i].c].minus = mp;
//                    ++mp %= MAX_SIZE;
//                }
//                t = result[points[i].c].minus;
//            }
//            result[points[i].c].subCnt();
//            points[i].c = t;
//            result[points[i].c].addCnt();
//        }
//    }
//    int count = 0;
//    for (auto item: result){
//        if (item.cnt) {
//            item.cnt = 0;
//            item.reset();
//            count++;
//        }
//    }
//    return count;
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
//        int N, M, a, b, c;
//        vector<Line> lines;
//        vector<Point> points;
//        cin >> N >> M;
//        for (int i = 0; i < N; ++i) {
//            cin >> a >> b >> c;
//            lines.push_back({a, b, c});
//        }
//        for (int i = 0; i < M; ++i) {
//            cin >> a >> b;
//            points.push_back({a, b, 0});
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << (findDivided(lines) == findPointDivided(lines, points) ? "PROTECTED" : "VULNERABLE");
//        cout << '\n';
//    }
//    return 0;
//}