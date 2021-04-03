package leetcode;

public class PalindromicSubstrings647 {
    public static void main(String[] args) {
        //Input: "abc"
        //Output: 3
        //Explanation: Three palindromic strings: "a", "b", "c".

        //Input: "aaa"
        //Output: 6
        //Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

//        String s = "abc";
//        int output = 3;

        String s = "aaa";
        int output = 6;

        Solution solution = new Solution();
        int result = solution.countSubstrings(s);
        System.out.println("output: " + output);
        System.out.println("result: " + result);
        System.out.println(output == result);
    }

    static class Solution {
        private int count = 0;

        public int countSubstrings(String s) {
            int length = s.length();
            for (int i = 0; i < length; i++) {
                for (int j = i + 1; j <= length; j++) {
                    String substring = s.substring(i, j);
                    if (isPalindromic(substring)) {
                        count++;
                    }
                }
            }

            return count;
        }

        private boolean isPalindromic(String substring) {
            int length = substring.length() - 1;
            for (int i = 0; i <= length / 2; i++) {
                if (substring.charAt(i) != substring.charAt(length - i)) {
                    return false;
                }
            }
            return true;
        }
    }
}
