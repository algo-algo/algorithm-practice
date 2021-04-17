//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class Node {
//public:
//    int x, y, d;
//    Node() : x(-1), y(-1), d(0) {}
//    Node(int x, int y, int d) : x(x), y(y), d(d) {}
//
//    bool operator==(const Node &rhs) const { return x == rhs.x &&y == rhs.y; }
//};
//
//class WormHole {
//public:
//    Node a, b;
//    void init() { a = Node(); b = Node(); }
//    void set(int x, int y) {
//        if (a.x != -1 && a.y != -1) {
//            b.x = x; b.y = y;
//        }
//        else {
//            a.x = x; a.y = y;
//        }
//    }
//    Node pass(int x, int y) const;
//};
//
//int sums[100][100];
//bool notCycle[100][100][4]; //0:상 1:하 2:좌 3:우
//WormHole holes[5];
//int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
//int blocks[5][4] = {
//        {1, 3, 0, 2},
//        {3, 0, 1, 2},
//        {2, 0, 3, 1},
//        {1, 2, 3, 0},
//        {1, 0, 3, 2}
//};
//int N;
//
//int reverse(int d) { return d + (d % 2 ? -1 : 1); }
//
//Node WormHole::pass(int x, int y) const {
//    if (x == a.x && y == a.y) return b;
//    return a;
//}
//
//int getBlockDirection(int block, int direction) {
//    return blocks[block - 1][direction];
//}
//
//void addVec(vector<int>& vec, int type) {
//    if (type == 0) {
//        if (vec[vec.size() - 1] != 0) vec.push_back(0);
//    }
//    else if (type == 1) {
//        if (vec[vec.size() - 1] == 0) vec.push_back(1);
//        else vec[vec.size() - 1]++;
//    }
//}
//
//int dfs(Node& start, Node& curr, vector<int>& vec) {
//    if (notCycle[start.x][start.y][start.d] && start == curr) return 2; // cycle or checked
//    notCycle[curr.x][curr.y][curr.d] = true;
//
//    curr.x += dx[curr.d]; curr.y += dy[curr.d];
//    if (curr.x < 0 || curr.x >= N || curr.y < 0 || curr.y >= N) { // wall
//        return 1;
//    }
//    if (sums[curr.x][curr.y] == 0) addVec(vec, 0); // next
//    else if (sums[curr.x][curr.y] == -1) { // black hole
//        return -1;
//    }
//    else if (sums[curr.x][curr.y] <= 5) { // block
//        int nextD = getBlockDirection(sums[curr.x][curr.y], curr.d);
//        if (nextD == reverse(curr.d)) return 1;
//        addVec(vec, 1);
//        curr.d = nextD;
//    }
//    else { // worm hole
//        Node node = holes[sums[curr.x][curr.y] - 6].pass(curr.x, curr.y);
//        curr.x = node.x;
//        curr.y = node.y;
//    }
//
//    return dfs(start, curr, vec);
//}
//
//int getResult() {
//    int maxVal = 0;
//
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            if (sums[i][j] != 0) continue;
//
//            for (int k = 0; k < 4; ++k) {
//                Node node(i, j, k);
//                Node curr(i, j, k);
//
//                vector<int> vec;
//                vec.push_back(0);
//                int result = dfs(node, curr, vec);
//
//                if (result == 2) {
//                    int count = 0;
//                    for (int item: vec) count += item;
//                    maxVal = max(maxVal, count);
//                    continue;
//                }
//
//                Node revNode(i, j, reverse(k));
//                Node revCurr(i, j, reverse(k));
//
//                vector<int> revVec;
//                revVec.push_back(0);
//                int result2 = dfs(revNode, revCurr, revVec);
//
//                // calculate
//                bool tmp = false;
//                int end1 = 0, common1 = 0;
//                for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
//                    if (*it == 0) tmp = true;
//                    else {
//                        if (!tmp) end1 += *it;
//                        else common1 += *it;
//                    }
//                }
//                tmp = false;
//                int end2 = 0, common2 = 0;
//                for (auto it = revVec.rbegin(); it != revVec.rend(); ++it) {
//                    if (*it == 0) tmp = true;
//                    else {
//                        if (!tmp) end2 += *it;
//                        else common2 += *it;
//                    }
//                }
//
//                int val1 = common1 + common2 + end2, val2 = end1 + common1 + common2;
//                if (result2 == 1) val1 = val1 * 2 + 1;
//                if (result == 1) val2 = val2 * 2 + 1;
//                maxVal = max(maxVal, max(val1, val2));
//            }
//        }
//    }
//
//    return maxVal;
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
//        for (auto & hole : holes) hole.init();
//
//        cin >> N;
//        int tmp;
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < N; ++j) {
//                cin >> tmp;
//                if (tmp >= 6) holes[tmp - 6].set(i, j);
//                sums[i][j] = tmp;
//
//                for (int k = 0; k < 4; ++k) notCycle[i][j][k] = false;
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getResult();
//        cout << '\n';
//    }
//    return 0;
//}