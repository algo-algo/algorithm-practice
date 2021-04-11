package leetcode;

public class MinimumWindowSubstring76 {
    public static void main(String[] args) {
        String s = "ADOBECODEBANC";
        String t = "ABC";
        String output = "BANC";

//        String s = "a";
//        String t = "a";
//        String output = "a";

        Solution solution = new Solution();
        String result = solution.minWindow(s, t);
        System.out.println("정답: " + output);
        System.out.println("나의 답: " + result);
        System.out.println(output.equals(result));
    }

    static class Solution {
        public String minWindow(String s, String t) {


            return "";
        }
    }
}
