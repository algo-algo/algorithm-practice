//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//class Solution {
//    inline vector<int> getVector(int a, int b) {
//        vector<int> result;
//        result.push_back(a);
//        result.push_back(b);
//        return result;
//    }
//public:
//    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//        vector<vector<int>> answer;
//        map<int, int> endHeight;
//        int prevHeight = -1, prevStart = -1;
//
//        for (auto building: buildings) {
//            while(!endHeight.empty() && endHeight.begin()->first < building[0]) {
//                int end = endHeight.begin()->first;
//                endHeight.erase(endHeight.begin());
//                int height = endHeight.begin()->second;
//                answer.push_back(getVector(end, endHeight.empty() ? 0 : height));
//                prevHeight = height;
//            }
//
//            if (building[2] > prevHeight) {
//                if (prevStart == building[0]) answer.pop_back();
//                answer.push_back(getVector(building[0], building[2]));
//                prevHeight = building[2];
//                prevStart = building[0];
//            }
//
//            auto ipUp = endHeight.upper_bound(building[1]);
//            if ((ipUp == endHeight.end() || building[2] > ipUp->second) && building[2] > endHeight[building[1]]) {
//                endHeight[building[1]] = building[2];
//                auto it = endHeight.find(building[1]);
//                if (it != endHeight.begin()) {
//                    it--;
//                    while (true) {
//                        bool last = it == endHeight.begin();
//                        auto tmpIt = it;
//                        it--;
//                        if (tmpIt->second <= building[2]) endHeight.erase(tmpIt);
//                        else break;
//                        if (last) break;
//                    }
//                }
//
////                std::map<int, int>::reverse_iterator itr(it);
////                for (itr++; itr != endHeight.rend(); itr++) {
////                    if (itr->second <= building[2]) endHeight.erase(itr->first);
////                    else break;
////                }
//            }
//        }
//
//        while(!endHeight.empty()) {
//            int end = endHeight.begin()->first;
//            endHeight.erase(endHeight.begin());
//            answer.push_back(getVector(end, endHeight.empty() ? 0 : endHeight.begin()->second));
//        }
//
//        return answer;
//    }
//};
//
//int main() {
//    Solution sol;
//    vector<vector<int>> vec { {1,38,219},{2,19,228},{2,64,106},{3,80,65},{3,84,8},{4,12,8},{4,25,14},{4,46,225},{4,67,187},{5,36,118},{5,48,211},{5,55,97},{6,42,92},{6,56,188},{7,37,42},{7,49,78},{7,84,163},{8,44,212},{9,42,125},{9,85,200},{9,100,74},{10,13,58},{11,30,179},{12,32,215},{12,33,161},{12,61,198},{13,38,48},{13,65,222},{14,22,1},{15,70,222},{16,19,196},{16,24,142},{16,25,176},{16,57,114},{18,45,1},{19,79,149},{20,33,53},{21,29,41},{23,77,43},{24,41,75},{24,94,20},{27,63,2},{31,69,58},{31,88,123},{31,88,146},{33,61,27},{35,62,190},{35,81,116},{37,97,81},{38,78,99},{39,51,125},{39,98,144},{40,95,4},{45,89,229},{47,49,10},{47,99,152},{48,67,69},{48,72,1},{49,73,204},{49,77,117},{50,61,174},{50,76,147},{52,64,4},{52,89,84},{54,70,201},{57,76,47},{58,61,215},{58,98,57},{61,95,190},{66,71,34},{66,99,53},{67,74,9},{68,97,175},{70,88,131},{74,77,155},{74,99,145},{76,88,26},{82,87,40},{83,84,132},{88,99,99} };
//    sol.getSkyline(vec);
//    return 0;
//}