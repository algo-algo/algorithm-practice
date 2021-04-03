package leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class TargetSum494 {
    public static void main(String[] args) {
//                int[] nums = {1, 1, 1, 1, 1};
//        int S = 3;
//        int output = 5;

        int[] nums = {35, 25, 24, 23, 2, 47, 39, 22, 3, 7, 11, 26, 6, 30, 5, 34, 10, 43, 41, 28};
        int S = 49;
        int output = 6266;

        Solution solution = new Solution();
        int result = solution.findTargetSumWays(nums, S);

        System.out.println("output: " + output);
        System.out.println("result: " + result);
        System.out.println(output == result);
    }

    static class Solution {
        private int answer = 0;

        public int findTargetSumWays(int[] nums, int S) {
            dfs(nums, 0, 0, S);
            return answer;
        }

        private void dfs(int[] nums, int depth, int target, int S) {
            if (depth == nums.length) {
                if (S == target) {
                    answer++;
                }
                return;
            }

            int number = nums[depth];
            dfs(nums, depth + 1, target + number, S);
            dfs(nums, depth + 1, target - number, S);
        }
    }
}
