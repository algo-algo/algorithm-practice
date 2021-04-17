//#include<iostream>
//#include<vector>
//#include<algorithm>
//#define MAX_WEIGHT 50
//
//using namespace std;
//
//int getResult(const vector<int>& boxes) {
//    int head = 0, tail = boxes.size() - 1;
//
//    while (head <= tail) {
//        int weight = boxes[tail];
//        int boxCount = 1;
//        while (weight * boxCount < MAX_WEIGHT) boxCount++;
//        head += boxCount - 1;
//        if (head > tail) break;
//        tail--;
//    }
//
//    return boxes.size() - tail - 1;
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
//        vector<int> boxes;
//        for (int i = 0; i < n; ++i) {
//            cin >> tmp;
//            boxes.push_back(tmp);
//        }
//        sort(boxes.begin(), boxes.end());
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(boxes);
//        cout << '\n';
//    }
//    return 0;
//}