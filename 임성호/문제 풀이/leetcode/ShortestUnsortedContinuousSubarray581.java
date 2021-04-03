package leetcode;

public class ShortestUnsortedContinuousSubarray581 {
    public static void main(String[] args) {
//        int[] nums = {2, 6, 4, 8, 10, 9, 15};
//        int output = 5;

//        int[] nums = {1, 3, 2, 2, 2, 2};
//        int output = 5;

//        int[] nums = {1, 4, 6, 3, 2, 2, 2, 2};
//        int output = 7;

//        int[] nums = {1, 3, 2, 3, 3};
//        int output = 2;

        int[] nums = {1, 2, 5, 3, 4};
        int output = 2;

//        int[] nums = {1,2,4,5,3};
//        int output = 3;
        // 정렬할 범위를 찾는다
        // 해당 범위에서 가장 작은 수를 찾는다
        // 그 수가 범위의 앞 수보다 작으면 -> start--
        // 그 수가 범위의 앞 수보다 크면 -> start 그대로

//        int[] nums = {2, 4, 3, 5, 1};
//        int output = 5;

//        int[] nums = {1, 2, 3, 4};
//        int output = 0;

//        int[] nums = {1};
//        int output = 0;

//        int[] nums = {2, 1};
//        int output = 2;

        Solution solution = new Solution();
        int result = solution.findUnsortedSubarray(nums);

        System.out.println("output: " + output);
        System.out.println("result: " + result);
        System.out.println(output == result);
    }

    static class Solution {
        public int findUnsortedSubarray(int[] nums) {
            int start = 0;
            int end = 0;
            boolean isSort = false;
            int[] index = {nums.length - 1};
            while (index[0] >= 1) {
                int targetNumber = nums[index[0]];
                int compareNumber = nums[index[0] - 1];
                if (targetNumber < compareNumber) {
                    if (!isSort) {
                        end = index[0];
                    }
                    isSort = true;
                    start = getStartIndex(nums, index, targetNumber);
                } else if (targetNumber == compareNumber) {
                    int originalIndex = index[0];
                    while (index[0] >= 0) {
                        if (nums[index[0]] > targetNumber) {
                            isSort = true;
                            end = originalIndex;
                            start = getStartIndex(nums, index, targetNumber);
                            break;
                        } else if (nums[index[0]] < targetNumber) {
                            break;
                        }
                        index[0]--;
                    }
                } else {
                    index[0]--;
                }
            }

            return isSort ? end - start + 1 : 0;
        }

        private int getStartIndex(int[] nums, int[] index, int targetNumber) {
            index[0] = index[0] - 1;
            while (index[0] >= 0) {
                if (nums[index[0]] <= targetNumber) {
                    break;
                }
                index[0]--;
            }
            return index[0] + 1;
        }
    }
}
