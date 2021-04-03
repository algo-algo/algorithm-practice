package leetcode;

import java.util.*;
import java.util.stream.Collectors;

public class ThreeSum15 {
    public static void main(String[] args) {

    }

    static class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            Set<List<Integer>> set = new HashSet<>();
            int length = nums.length;

            for (int i = 0; i < length - 2; i++) {
                for (int j = i + 1; j < length - 1; j++) {
                    for (int k = j + 1; k < length; k++) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            List<Integer> list = Arrays.asList(nums[i], nums[j], nums[k]);
                            Collections.sort(list);
                            set.add(list);
                        }
                    }
                }
            }

            return set.stream()
                    .collect(Collectors.toList());
        }
    }
}
