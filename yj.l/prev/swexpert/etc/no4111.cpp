//#include<iostream>
//#include<set>
//#include<map>
//
//using namespace std;
//
//int getResult(set<int>& data, int k) {
//    int size = data.size();
//    if (size <= k) return 0;
//
//    map<int, int> cntMap;
//    auto it = data.begin();
//    for (auto it2 = data.begin(); it2 != data.end(); ++it2) {
//        if (++it == data.end()) break;
//        cntMap[*it - *it2]++;
//    }
//
//    int count = size - k;
//    int answer = 0;
//
//    for (auto p: cntMap) {
//        if (count <= p.second) {
//            answer += p.first * count;
//            break;
//        }
//        answer += p.first * p.second;
//        count -= p.second;
//    }
//    return answer;
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
//        int n, k, val;
//        set<int> data;
//        cin >> n >> k;
//        for (int i = 0; i < n; ++i) {
//            cin >> val;
//            data.insert(val);
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(data, k);
//        cout << '\n';
//    }
//    return 0;
//}