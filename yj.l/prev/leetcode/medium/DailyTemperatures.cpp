//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//
//using namespace std;
//
//class Solution {
//public:
////    vector<int> dailyTemperatures(vector<int>& T) {
////        vector<int> result(T.size(), 0);
////        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
////        for (int i = 0; i < T.size(); i++) {
////            int temperature = T[i];
////            while (!pq.empty() && pq.top().first < temperature) {
////                result[pq.top().second] = i - pq.top().second;
////                pq.pop();
////            }
////
////            pq.push({temperature, i});
////        }
////
////        return result;
////    }
//    vector<int> dailyTemperatures(vector<int>& T) {
//        vector<int> result(T.size(), 0);
//        stack<int> st;
//        for (int i = T.size() - 1; i >= 0; i--) {
//            int temperature = T[i];
//
//            while (!st.empty() && T[st.top()] <= temperature)
//                st.pop();
//
//            if (!st.empty()) result[i] = st.top() - i;
//            st.push(i);
//        }
//
//        return result;
//    }
//};
//
//int main() {
//    Solution checkMap;
//    vector<int> T;
//    T.push_back(4);
//    T.push_back(5);
//    T.push_back(6);
//    T.push_back(2);
//    T.push_back(0);
//    T.push_back(3);
//    T.push_back(7);
//    T.push_back(4);
//
//    checkMap.dailyTemperatures(T);
//    return 0;
//}