//#include<iostream>
//#include<queue>
//#include<set>
//#include<string>
//
//using namespace std;
//
//int dx[4] = {-1, 1, 0, 0};
//int dy[4] = {0, 0, -1, 1};
//char sums[20][20];
//set<pair<int, int>> memSet[20][20];
//
//class Node {
//    static int remain(int n, int max) {
//        if (n < 0) n += max;
//        return n % max;
//    }
//public:
//    static int maxX, maxY;
//    int x, y;
//    int mem, dir;
//    Node(int x, int y, int mem, int dir) {
//        this->x = remain(x, maxX);
//        this->y = remain(y, maxY);
//        this->mem = remain(mem, 16);
//        this->dir = dir;
//    }
//    Node(Node const &n, int dir) : Node(n, dir, n.mem) {}
//    Node(Node const &n, int dir, int mem) : Node(n.x + dx[dir], n.y + dy[dir], mem, dir) {}
//};
//
//int Node::maxX = 0;
//int Node::maxY = 0;
//
//bool isChecked(Node* np) {
//    if (memSet[np->x][np->y].insert({np->mem, np->dir}).second) return false;
//    return true;
//}
//
//string getResult(int maxX, int maxY) {
//    for (int i = 0; i < maxX; i++) {
//        for (int j = 0; j < maxY; j++) {
//            memSet[i][j].clear();
//        }
//    }
//
//    Node::maxX = maxX;
//    Node::maxY = maxY;
//    queue<Node> que;
//    Node* np;
//    np = new Node(0, 0, 0, 3);
//    if (!isChecked(np)) que.push(*np);
//
//    while (!que.empty()) {
//        Node n = que.front();
//        que.pop();
//        char ch = sums[n.x][n.y];
//        int dir;
//
//        switch (ch) {
//            case '^':
//                np = new Node(n, 0);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case 'v':
//                np = new Node(n, 1);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case '<':
//                np = new Node(n, 2);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case '>':
//                np = new Node(n, 3);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case '_':
//                dir = n.mem == 0 ? 3 : 2;
//                np = new Node(n, dir);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case '|':
//                dir = n.mem == 0 ? 1 : 0;
//                np = new Node(n, dir);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case '?':
//                for (int i = 0; i < 4; i++) {
//                    np = new Node(n, i);
//                    if (!isChecked(np)) que.push(*np);
//                }
//                break;
//            case '.':
//                np = new Node(n, n.dir);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case '+':
//                np = new Node(n, n.dir, n.mem + 1);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case '-':
//                np = new Node(n, n.dir, n.mem - 1);
//                if (!isChecked(np)) que.push(*np);
//                break;
//            case '@':
//                return "YES";
//            default:
//                np = new Node(n, n.dir, ch - '0');
//                if (!isChecked(np)) que.push(*np);
//                break;
//        }
//    }
//
//    return "NO";
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
//        int R, C;
//        cin >> R >> C;
//        for (int i = 0; i < R; i++) {
//            for(int j = 0; j < C; j++) {
//                cin >> sums[i][j];
//            }
//        }
//
//        string result = getResult(R, C);
//
//        cout << "#" << test_case << " ";
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
//}