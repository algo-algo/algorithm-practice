//#include<iostream>
//#include<queue>
//#define START 175
//
//using namespace std;
//int N, M, K;
//int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
//
//class Node {
//public:
//    int x, y, life, time;
//    Node(int x, int y, int life, int time) : x(x), y(y), life(life), time(time) {}
//};
//
//Node* sums[350][350];
//
//int getResult(queue<Node*> alive) {
//    for (int t = 1; t <= K; ++t) {
//
//        queue<Node*> next;
//        while (!alive.empty()) {
//            Node* n = alive.front();
//            alive.pop();
//
//            if (n->time + n->life * 2 > t) next.push(n);
//
//            if (n->time + n->life + 1 != t) continue;
//
//            for (int i = 0; i < 4; ++i) {
//                int nx = n->x + dx[i], ny = n->y + dy[i];
//                if (nx == 201 && ny == 203 ) {
//                    int a = 1;
//                }
//
//                if (sums[nx][ny] != nullptr) {
//                    if (sums[nx][ny]->time == t){
//                        if (n->life > sums[nx][ny]->life){
//                            sums[nx][ny]->life = n->life;
//                        }
//                    }
//
//                    continue;
//                }
//
//                sums[nx][ny] = new Node(nx, ny, n->life, t);
//                next.push(sums[nx][ny]);
//            }
//        }
//
//        swap(alive, next);
//    }
//
//    return alive.size();
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
//        for (auto & i : sums){
//            for (auto & j : i) {
//                if (j) {
//                    free(j);
//                }
//                j = nullptr;
//            }
//        }
//
//        cin >> N >> M >> K;
//
//        int val;
//        queue<Node*> que;
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < M; ++j) {
//                cin >> val;
//                if (val == 0) continue;
//                sums[START + i][START + j] = new Node(START + i, START + j, val, 0);
//                que.push(sums[START + i][START + j]);
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(que);
//        cout << '\n';
//    }
//    return 0;
//}