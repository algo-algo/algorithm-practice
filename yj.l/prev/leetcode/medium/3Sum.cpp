//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//class Data {
//public:
//    int a, b, c;
//    Data(int a, int b, int c) : a(a), b(b), c(c) {}
//    bool operator==(const Data &rhs) const { return a == rhs.a && b == rhs.b && c == rhs.c; }
//    bool operator<(const Data &rhs) const {
//        if (a < rhs.a) return true;
//        if (rhs.a < a) return false;
//        if (b < rhs.b) return true;
//        if (rhs.b < b) return false;
//        return c < rhs.c;
//    }
//};
//
//class Solution {
//    int dp[200001];
//    map<Data, bool> checkMap;
//    bool check(int a, int b, int c) {
//        if (b < a) swap(a, b);
//        if (c < a) {
//            swap(a, c);
//            swap(b, c);
//        }
//        else if (c < b) swap(b, c);
//
//        auto& result = checkMap[{a, b, c}];
//        if (result) return false;
//        result = true;
//        return true;
//    }
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//        int size = nums.size();
//        int zeroIdx;
//        for (zeroIdx = 0; zeroIdx < size; ++zeroIdx)
//            if (nums[zeroIdx] >= 0) break;
//        if (zeroIdx == 0 && size >= 3 && !nums[0] && !nums[1] && !nums[2]) result.push_back({0, 0, 0});
//        if (size < 3 || zeroIdx == size || zeroIdx == 0) return result;
//
//        for (int i = 0; i <= zeroIdx; ++i) {
//            int ni = nums[i];
//            int j = i + 1;
//            int k = size - 1;
//            while (j < k) {
//                int sum = ni + nums[j] + nums[k];
//                if (sum == 0) {
//                    result.push_back({ni, nums[j], nums[k] });
//
//                    while (j < k && nums[j] == nums[j + 1]) ++j;
//                    ++j;
//                    while (j < k && nums[k] == nums[k - 1]) --k;
//                    --k;
//                }
//                else if (sum < 0) ++j;
//                else --k;
//            }
//            while (i < zeroIdx && nums[i] == nums[i + 1]) ++i;
//        }
//
//        return result;
//    }
//
////    vector<vector<int>> threeSum(vector<int>& nums) {
////        vector<vector<int>> result;
////        if (nums.size() < 3) return result;
////
////        vector<int> pos, neg;
////        for (int& num: nums) {
////            int val = num + 100000;
////            dp[val]++;
////            if (num < 0) neg.push_back(num);
////            else if (num > 0) pos.push_back(num);
////        }
////
////        if (dp[100000] >= 3) result.push_back({0, 0, 0});
////        for (int& pn: pos) {
////            for (int& nn: neg) {
////                if (dp[100000 - pn - nn] == 0) continue;
////                int val = - pn - nn;
////                if ((val == pn || val == nn) && dp[100000 + val] < 2) continue;
////                if (!check(pn, nn, val)) continue;
////                result.push_back({pn, nn, val});
////            }
////        }
////
////        return result;
////    }
////    vector<vector<int>> threeSum(vector<int>& nums) {
////        vector<vector<int>> result;
////
////        for (int i = 0; i < nums.size(); ++i) {
////            for (int j = i + 1; j < nums.size(); ++j) {
////                if (nums[i] + nums[j] > 100000 || nums[i] + nums[j] < -100000) continue;
////                if (dp[100000 - nums[i] - nums[j]] == 0) continue;
////                if (!check(nums[i], nums[j], -nums[i] - nums[j])) continue;
////                result.push_back({nums[i], nums[j], -nums[i] - nums[j]});
////            }
////            int val = nums[i] + 100000;
////            dp[val]++;
////        }
////
////        return result;
////    }
////    vector<vector<int>> threeSum(vector<int>& nums) {
////        map<int, int> numMap;
////        for (int& num: nums) numMap[num]++;
////
////        vector<vector<int>> result;
////
////        for (auto it = numMap.begin(); it != numMap.end(); it++) {
////            if (it->first == 0 && it->second >= 3) result.push_back({0, 0, 0});
////            int val = -it->first;
////            auto head = it;
////            if (it->second == 1) head++;
////            auto tail = numMap.end();
////            tail--;
////
////            while (head->first < tail->first) {
////                if (head->first + tail->first < val) head++;
////                else if (head->first + tail->first > val) tail--;
////                else {
////                    result.push_back({it->first, head->first, tail->first});
////                    if (head != tail) head++;
////                }
////            }
////            if (head == tail && head != it && head->second >= 2 && head->first * 2 == val)
////                result.push_back({it->first, head->first, tail->first});
////        }
////
////        return result;
////    }
//};
//
//int main() {
//    return 0;
//}