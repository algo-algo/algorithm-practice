//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//int dx[] = {0, 0, -1, 1};
//int dy[] = {1, -1, 0, 0};
//
//inline bool isReversed(int d1, int d2) {
//    return d1 + (d1 % 2 == 0 ? 1 : -1) == d2;
//}
//
//class Node {
//public:
//    int x, y, d, k;
//    bool bombed, notCycle;
//    Node(int x, int y, int d, int k) : x(x), y(y), d(d), k(k) { bombed = notCycle = false; }
//    double whenBomb(const Node& n) const {
//        if (bombed || n.bombed) return 0;
//
//        if (d == n.d) return 0; // 같은 방향
//
//        if (isReversed(d, n.d)) { // 반대 방향
//            if (d < 2) { // 상하
//                if (x != n.x) return 0;
//                if (y * dy[d] + n.y * dy[n.d] > 0) return 0;
//                return y > n.y ? (y - n.y) / (double)2 : (n.y - y) / (double)2;
//            }
//            else { // 좌우
//                if (y != n.y) return 0;
//                if (x * dx[d] + n.x * dx[n.d] > 0) return 0;
//                return x > n.x ? (x - n.x) / (double)2 : (n.x - x) / (double)2;
//            }
//        }
//        else { // 그 외
//            int tx = x > n.x ? x - n.x : n.x - x;
//            int ty = y > n.y ? y - n.y : n.y - y;
//            if (tx != ty) return 0;
//            if (x + dx[d] * tx != n.x + dx[n.d] * tx ||
//                y + dy[d] * ty != n.y + dy[n.d] * ty) return 0;
//            return tx;
//        }
//    }
//};
//
//class Bomb {
//public:
//    Node * a, * b;
//    double time;
//    Bomb(Node *a, Node *b, double time) : a(a), b(b), time(time) {}
//    bool operator<(const Bomb &rhs) const { return time > rhs.time; }
//    bool operator>(const Bomb &rhs) const { return rhs < *this; }
//};
//
//priority_queue<Bomb> getBombs(vector<Node>& atoms) {
//    priority_queue<Bomb> pq;
//
//    int size = atoms.size();
//    for (int i = 0; i < size; ++i) {
//        for (int j = i + 1; j < size; ++j) {
//            double time = atoms[i].whenBomb(atoms[j]);
//            if (time == 0) continue;
//            pq.push({&atoms[i], &atoms[j], time});
//        }
//    }
//    return pq;
//}
//
//int bombNGetEnergy(vector<Bomb>& bombs) {
//    int energy = 0;
//    vector<Node*> bombedNode;
//    for (Bomb& bomb: bombs) {
//        auto & n1 = *bomb.a, & n2 = *bomb.b;
//        if (n1.bombed || n2.bombed) continue;
//        if (!n1.notCycle) {
//            energy += n1.k;
//            n1.notCycle = true;
//            bombedNode.push_back(&n1);
//        }
//        if (!n2.notCycle) {
//            energy += n2.k;
//            n2.notCycle = true;
//            bombedNode.push_back(&n2);
//        }
//    }
//    for (auto& node: bombedNode) {
//        node->bombed = true;
//    }
//
//    return energy;
//}
//
//int getEnergy(vector<Node> atoms) {
//    int energy = 0;
//
//    auto pq = getBombs(atoms);
//    vector<Bomb> tmpBombs;
//    double prev = pq.empty() ? 0 : pq.top().time;
//    while (!pq.empty()) {
//        auto bomb = pq.top();
//        pq.pop();
//        if (prev != bomb.time) {
//            energy += bombNGetEnergy(tmpBombs);
//            tmpBombs.clear();
//            prev = bomb.time;
//        }
//        tmpBombs.push_back(bomb);
//    }
//    energy += bombNGetEnergy(tmpBombs);
//
//    return energy;
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
//        int N, x, y, d, k;
//        vector<Node> vec;
//        cin >> N;
//        for (int i = 0; i < N; ++i) {
//            cin >> x >> y >> d >> k;
//            vec.push_back({x + 1000, y + 1000, d, k});
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getEnergy(vec);
//        cout << '\n';
//    }
//    return 0;
//}