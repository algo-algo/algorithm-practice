//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class Node {
//public:
//    long long x, y;
//    Node(long long x, long long y) : x(x), y(y) {}
//    bool isRight(const Node &a, const Node &b) const {
//        return (a.x - x) * (b.x - x) == - (a.y - y) * (b.y - y);
//    }
//};
//
//class Triangle {
//public:
//    Node a, b, c;
//    Triangle(const Node &a, const Node &b, const Node &c) : a(a), b(b), c(c) {}
//    bool isRight() {
//        return a.isRight(b, c) || a.isRight(c, b) || b.isRight(c, a);
//    }
//};
//
//int getResult(vector<Node> nodes, int size) {
//    int result = 0;
//    for (int i = 0; i < size; ++i) {
//        for (int j = i + 1; j < size; ++j) {
//            for (int k = j + 1; k < size; ++k) {
//                Triangle t(nodes[i], nodes[j], nodes[k]);
//                if (t.isRight()) result++;
//            }
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
//
//    int n, x, y;
//    vector<Node> nodes;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> x >> y;
//        nodes.push_back({x, y});
//    }
//
//    cout << getResult(nodes, n) << '\n';
//    return 0;
//}