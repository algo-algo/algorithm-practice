//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int moveA[101], moveB[101];
//int dx[] = {0, -1, 0, 1, 0};
//int dy[] = {0, 0, 1, 0, -1};
//
//class Person {
//public:
//    int x, y;
//    Person(int x, int y): x(x), y(y) {}
//    void move(int d) { x += dx[d]; y += dy[d]; }
//};
//
//class BatteryCharger{
//public:
//    int x, y, range, val;
//    BatteryCharger(int x, int y, int range, int val) : x(x), y(y), range(range), val(val) {}
//    bool operator<(const BatteryCharger &rhs) const { return val < rhs.val; }
//    bool operator>(const BatteryCharger &rhs) const { return rhs < *this; }
//    bool canCharge(const Person& p) {
//        int tmpx = x - p.x; int tmpy = y - p.y;
//        return (tmpx > 0 ? tmpx : -tmpx) + (tmpy < 0 ? -tmpy : tmpy) <= range;
//    }
//};
//
//int getValue(const vector<BatteryCharger>& chargers, const Person& A, const Person& B) {
//    bool a = false, b = false;
//    int value = 0;
//    for (auto charger: chargers) {
////        if (a + b == 2) {
////            if (charger.canCharge(A) || charger.canCharge(B))
////                return value + charger.val;
////        }
////        else if (a + b == 0) {
////            a = charger.canCharge(A);
////            b = charger.canCharge(B);
////            if (a || b) value = charger.val;
////        }
////        else if (a == 1) {
////            if (charger.canCharge(B))
////                return value + charger.val;
////        }
////        else if (b == 1) {
////            if (charger.canCharge(A))
////                return value + charger.val;
////        }
//
//        if (!a && !b) {
//            a = charger.canCharge(A);
//            b = charger.canCharge(B);
//            if (a || b) value = charger.val;
//        }
//        else {
//            if (a && charger.canCharge(B) || b && charger.canCharge(A))
//                return value + charger.val;
//        }
//    }
//    return value;
//}
//
//int getResult(vector<BatteryCharger> chargers, int time) {
//    Person A(1, 1), B(10, 10);
//    sort(chargers.rbegin(), chargers.rend());
//    int sum = 0;
//
//    for (int i = 0; i <= time; ++i) {
//        A.move(moveA[i]);
//        B.move(moveB[i]);
//
//        sum += getValue(chargers, A, B);
//    }
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
//        vector<BatteryCharger> chargers;
//        int m, t;
//        cin >> m >> t;
//        for (int i = 1; i <= m; ++i) cin >> moveA[i];
//        for (int i = 1; i <= m; ++i) cin >> moveB[i];
//        for (int i = 0; i < t; ++i) {
//            int tmp1, tmp2, tmp3, tmp4;
//            cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
//            chargers.push_back({tmp2, tmp1, tmp3, tmp4});
//        }
//
//        auto result = getResult(chargers, m);
//        cout << "#" << test_case << ' ';
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
//}