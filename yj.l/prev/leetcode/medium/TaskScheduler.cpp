//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//    int alpha[26];
//public:
//    int leastInterval(vector<char>& tasks, int n) {
//        for (auto & item: alpha) item = 0;
//        for (char ch: tasks) alpha[ch - 'A']++;
//
//        int max = 0, maxCount = 0, sum = 0;
//        for (int count: alpha) {
//            if (count == 0) continue;
//
//            if (count > max){
//                max = count;
//                maxCount = 1;
//            }
//            else if (count == max) {
//                maxCount++;
//            }
//            sum += count;
//        }
//
//        if ((max - 1) * n > sum - max - (maxCount - 1)) {
//            return (max - 1) * n + max + maxCount - 1;
//        }
//        else return sum;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<char> tasks;
//    tasks.push_back('a');
//    tasks.push_back('a');
//    tasks.push_back('b');
//    solution.leastInterval(tasks, 2);
//    return 0;
//}