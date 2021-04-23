package leetcode;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class TheSkylineProblem218 {
    public static void main(String[] args) {
        int[][] buildings = {
                {2, 9, 10},
                {3, 7, 15},
                {5, 12, 12},
                {15, 20, 10},
                {19, 24, 8}
        };
        List<List<Integer>> output = Arrays.asList(
                Arrays.asList(2, 10),
                Arrays.asList(3, 15),
                Arrays.asList(7, 12),
                Arrays.asList(12, 0),
                Arrays.asList(15, 10),
                Arrays.asList(20, 8),
                Arrays.asList(24, 0)
        );

        Solution solution = new Solution();
        List<List<Integer>> result = solution.getSkyline(buildings);
        System.out.print("output: " + "[");
        output.forEach(list -> {
            System.out.print("[");
            list.forEach(number -> {
                System.out.print(number + " ");
            });
            System.out.print("] ");
        });
        System.out.println("]");

        System.out.print("my answer: " + "[");
        result.forEach(list -> {
            System.out.print("[");
            list.forEach(number -> {
                System.out.print(number + " ");
            });
            System.out.print("] ");
        });
        System.out.print("]");
    }

    static class Solution {
        public List<List<Integer>> getSkyline(int[][] buildings) {

            return Collections.emptyList();
        }
    }
}
