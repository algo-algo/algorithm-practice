//#include<iostream>
//#include<sstream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//char nums[29];
//int N, K;
//
//int getResult() {
//    int len = N / 4;
//    auto* ss = new stringstream();
//    vector<int> vec;
//    for (int i = 0; i < len; ++i) {
//        for (int j = 0; j < N; ++j) {
//            *ss << nums[(i + j) % N];
//
//            if (j % len == len - 1) {
//                int val;
//                *ss >> hex >> val;
//                ss = new stringstream();
//                vec.push_back(val);
//            }
//        }
//    }
//    sort(vec.begin(), vec.end());
//
//    int count = 0, prev = -1;
//    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
//        if (*it == prev) continue;
//        count++;
//        if (count == K) return *it;
//    }
//    return -1;
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
//        cin >> N >> K;
//        cin >> nums;
//
//        cout << "#" << test_case << ' ';
//        cout << getResult();
//        cout << '\n';
//    }
//    return 0;
//}