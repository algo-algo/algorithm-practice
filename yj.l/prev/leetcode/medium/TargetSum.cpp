//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//    int max[20], min[20];
//public:
//    int findTargetSumWays(vector<int>& nums, int S) {
//        int maxSum = 0, minSum = 0;
//        for (int& num: nums) {
//            int abs = num > 0 ? num : -num;
//            maxSum += abs;
//            minSum -= abs;
//        }
//        if (S > maxSum || S < minSum) return 0;
//        int bigger = maxSum > -minSum ? maxSum : -minSum;
//        int length = bigger * 2 + 1;
//
//        vector<int> sums(length, 0);
//
//        sums[bigger + nums[0]]++;
//        sums[bigger - nums[0]]++;
//        for (int i = 1; i < nums.size(); ++i) {
//            vector<int> tmp(length, 0);
//            for (int j = 0; j < length; ++j) {
//                int& sum = sums[j];
//                if (sum == 0) continue;
//                tmp[j + nums[i]] += sum;
//                tmp[j - nums[i]] += sum;
//            }
//            tmp.swap(sums);
//        }
//
//        return sums[bigger + S];
//    }
////    int findTargetSumWays(vector<int>& nums, int S) {
////        for (auto& sum: sums) sum = 0;
////
////        int maxTmp = 0, minTmp = 0;
////        for (int i = nums.size() - 1; i >= 0; --i) {
////            int abs = nums[i] > 0 ? nums[i] : -nums[i];
////            max[i] = maxTmp += abs;
////            min[i] = minTmp -= abs;
////        }
////
////        sums[1000 + nums[0]]++;
////        sums[1000 - nums[0]]++;
////        for (int i = 1; i < nums.size(); ++i) {
////            for (int j = 0; j < 2000; ++j) {
////                int& sum = sums[j];
////                if (sum == 0) continue;
////                if (sum + max[i] >= S) sums[j + nums[i]] += sum;
////                if (sum - max[i] <= S) sums[j - nums[i]] += sum;
////            }
////        }
////
////        return sums[1000 + S];
////    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums;
//    for (int i = 0; i < 5; ++i) nums.push_back(1);
//    cout << solution.findTargetSumWays(nums, 3) << endl;
//
//    vector<int> nums2;
//    for (int i = 0; i < 16; ++i) nums2.push_back(1);
//    cout << solution.findTargetSumWays(nums2, 0) << endl;
//    return 0;
//}