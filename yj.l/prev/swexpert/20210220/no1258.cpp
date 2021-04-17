//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//bool sums[100][100];
//bool check[100][100];
//
//class Node{
//public:
//    int x, y;
//    Node(int x, int y) : x(x), y(y) {}
//    bool operator<(const Node &rhs) const {
//        int p1 = x * y;
//        int p2 = rhs.x * rhs.y;
//        if (p1 == p2) {
//            return x < rhs.x;
//        }
//        return p1 < p2;
//    }
//    bool operator>(const Node &rhs) const { return rhs < *this; }
//};
//
//Node getRect(int x, int& y, int size) {
//    int i, j;
//    for (i = x; i < size; ++i) {
//        if (!sums[i][y]) break;
//        for (j = y; sums[i][j] && j < size; ++j) {
//            check[i][j] = true;
//        }
//    }
//    return {i - x, j - y};
//}
//
//void printResult(int size) {
//    vector<Node> vec;
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            if (sums[i][j] && !check[i][j])
//                vec.push_back(getRect(i, j, size));
//        }
//    }
//
//    sort(vec.begin(), vec.end());
//    cout << vec.size() << ' ';
//    for (auto pair: vec) {
//        cout << pair.x << ' ' << pair.y << ' ';
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
//        int n, tmp;
//        cin >> n;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                cin >> tmp;
//                sums[i][j] = tmp != 0;
//                check[i][j] = false;
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        printResult(n);
//        cout << '\n';
//    }
//    return 0;
//}