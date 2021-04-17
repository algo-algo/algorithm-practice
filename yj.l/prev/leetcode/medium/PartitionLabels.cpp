//#include <iostream>
//#include <vector>
//
//using namespace std;
//class MinMax {
//public:
//    int minVal, maxVal;
//    MinMax() : minVal(-1), maxVal(-1) {}
//    MinMax(int minVal, int maxVal) : minVal(minVal), maxVal(maxVal) {}
//};
//MinMax minMax[26];
//
//class Solution {
//public:
//    int getNext(int p) {
//        int tmpMax = p;
//        for (int i = 0; i < 26; ++i) {
//            if (minMax[i].minVal == -1) continue;
//            if (minMax[i].minVal <= p && minMax[i].maxVal > tmpMax) {
//                tmpMax = minMax[i].maxVal;
//            }
//        }
//        return p == tmpMax ? p : getNext(tmpMax);
//    }
//    vector<int> partitionLabels(string S) {
//        for (int i = 0; i < 26; ++i) minMax[i] = {-1, -1};
//        for (int i = 0; i < S.length(); i++) {
//            int idx = S[i] - 'a';
//            if (minMax[idx].minVal == -1) minMax[idx].minVal = i;
//            minMax[idx].maxVal = i;
//        }
//
//        vector<int> result;
//        int idx = -1, tmp;
//        while ((tmp = getNext(idx + 1)) < S.length()) {
//            result.push_back(tmp - idx);
//            idx = tmp;
//        }
//        return result;
//    }
//};
//
//int main() {
//    Solution checkMap;
//    checkMap.partitionLabels("abcdefg");
//    return 0;
//}