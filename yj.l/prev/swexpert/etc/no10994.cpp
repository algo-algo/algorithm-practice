//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class Node {
//public:
//    int p; bool h;
//    Node(int p, bool h) { this->p = p; this->h = h; }
//};
//
//vector<Node> vec;
//
//void calculate(bool having, int prev, int curr, int& price, int& count) {
//    if (having) return;
//    if (price + prev < curr) {
//        count++;
//        price += prev;
//    }
//}
//
//pair<int, int> getResult(int size, int max) {
//    int count = 0;
//    int price = 0;
//
//    for (int i = 1; i < size; ++i) {
//        if (price + vec[i - 1].p >= max) return {count, max - price};
//        calculate(vec[i - 1].h, vec[i - 1].p, vec[i].p, price, count);
//    }
//    if (price + vec[size - 1].p >= max) return {count, max - price};
//    calculate(vec[size - 1].h, vec[size - 1].p, 1000000000, price, count);
//
//    return {count, count == 0 ? max - 1 : max - price};
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
//        vec.clear();
//        int n, k;
//        cin >> n >> k;
//        for (int i = 0; i < n; ++i) {
//            int p; bool h;
//            cin >> p >> h;
//            vec.push_back(Node(p, h));
//        }
//
//        auto pair = getResult(n, k);
//        cout << "#" << test_case << " ";
//        cout << pair.first << " " << pair.second;
//        cout << '\n';
//    }
//    return 0;
//}