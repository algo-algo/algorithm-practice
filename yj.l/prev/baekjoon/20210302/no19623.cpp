//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//
//using namespace std;
//
//class Node {
//public:
//    int start, end, count;
//    Node(int start, int anEnd, int count) : start(start), end(anEnd), count(count) {}
//    bool operator<(const Node &rhs) const {
//        if (start < rhs.start) return true;
//        if (rhs.start < start) return false;
//        return end < rhs.end;
//    }
//};
//
//int getResult(vector<Node>& nodes) {
//    map<int, int> tmpMap;
//    sort(nodes.begin(), nodes.end());
//
//    int count = 0;
//    for (Node& node: nodes) {
//        auto it = tmpMap.begin();
//        while ((it = tmpMap.begin()) != tmpMap.end()) {
//            if (it->first > node.start) break;
//            if (it->second > count) count = it->second;
//            tmpMap.erase(it);
//        }
//
//        tmpMap[node.end] = count + node.count;
//    }
//
//    for (auto& p: tmpMap) {
//        if (p.second <= count) continue;
//        count = p.second;
//    }
//
//    return count;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int n, x, y, z;
//    vector<Node> vec;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> x >> y >> z;
//        vec.push_back({x, y, z});
//    }
//
//    cout << getResult(vec) << '\n';
//    return 0;
//}