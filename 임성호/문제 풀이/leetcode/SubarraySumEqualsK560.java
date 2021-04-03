package leetcode;

import java.util.HashMap;
import java.util.Map;

public class SubarraySumEqualsK560 {
    public static void main(String[] args) {
//        int[] nums = {1, 1, 1};
//        int k = 2;
//        int output = 2;

//        int[] nums = {1, 2, 3};
//        int k = 3;
//        int output = 2;

        int[] nums = {1, -1, 0};
        int k = 0;
        int output = 3;

        Solution solution = new Solution();
        int result = solution.subarraySum(nums, k);
        System.out.println("output: " + output);
        System.out.println("result: " + result);
        System.out.println(output == result);
    }

    static class Solution {
        public int subarraySum(int[] nums, int k) {
            int result = 0;
            int sum = 0;
            Map<Integer, Integer> countMap = new HashMap<>();
            countMap.put(sum, 1);
            for (int i = 0; i < nums.length; i++) {
                sum += nums[i];
                if (countMap.containsKey(sum - k)) {
                    result += countMap.get(sum - k);
                }
                countMap.put(sum, countMap.getOrDefault(sum, 0) + 1);
            }

            return result;
        }
    }
}
