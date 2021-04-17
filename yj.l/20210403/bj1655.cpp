//#include<iostream>
//#include<vector>
//#include<map>
//
//using namespace std;
//
//vector<int> getResult(vector<int>& vec) {
//    vector<int> answer;
//    map<int, int> numMap;
//    int st = 0;
//    numMap[vec[0]] = 1;
//    answer.push_back(vec[0]);
//    auto it = numMap.begin();
//
//    for (int i = 1; i < vec.size(); i++) {
//        int next = vec[i];
//        numMap[next]++;
//        if (i % 2 == 0) {
//            if (next >= it->first) {
//                if (++st >= it->second) {
//                    it++; st = 0;
//                }
//            }
//        }
//        else {
//            if (next < it->first) {
//                if (--st < 0) {
//                    it--; st = it->second - 1;
//                }
//            }
//        }
//        answer.push_back(it->first);
//    }
//
//    return answer;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int n, t;
//    vector<int> vec;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> t;
//        vec.push_back(t);
//    }
//    vector<int> result = getResult(vec);
//    for (int item: result) {
//        cout << item << ' ';
//    }
//    cout << '\n';
//    return 0;
//}