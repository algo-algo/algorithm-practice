package leetcode;

public class RegularExpressionMatching10 {
    public static void main(String[] args) {
//        String s = "aa";
//        String p = "a";
//        boolean output = false;

//        String s = "aa";
//        String p = "a*";
//        boolean output = true;

//        String s = "ab";
//        String p = ".*";
//        boolean output = true;

//        String s = "aab";
//        String p = "c*a*b";
//        boolean output = true;

//        String s = "mississippi";
//        String p = "mis*is*p*.";
//        boolean output = false;

//        String s = "aaa";
//        String p = "ab*a";
//        boolean output = true;

        String s = "a";
        String p = "ab*";
        boolean output = true;

        Solution solution = new Solution();
        boolean result = solution.isMatch(s, p);
        System.out.println("정답: " + output);
        System.out.println("나의 답: " + result);
    }

    static class Solution {
        public boolean isMatch(String s, String p) {
            if (".*".equals(p)) {
                return true;
            } else if (!p.contains(".") && !p.contains("*")) {
                return s.equals(p);
            }

            int patternIndex = 0;
            int stringIndex = 0;
            while (patternIndex < p.length()) {
                char patternCharacter = p.charAt(patternIndex);
                char stringCharacter = s.charAt(stringIndex);

                // 패턴 다음 글자에 * 가 포함된 경우 -> 패턴 다음 글자를 확인하려면
                // 인덱스 + 1이 패턴 길이보다 작아야 한다.
                if (patternIndex + 1 < p.length()) {
                    char nextPatternCharacter = p.charAt(patternIndex + 1);
                    if (nextPatternCharacter == '*') {
                        // 패턴 다음 글자에 * 인데 앞의 글자가 0번 반복인 경우
                        // 패턴 다음 글자에 * 인데 앞의 글자가 계속 반복인 경우

                    } else {
                        // 패턴 다음 글자가 . 또는 일반 문자인 경우
                        // if 문을 실행하지 않고 아래 조건을 실행해야 한다. -> continue
                        continue;
                    }
                }
                // 두 문자가 같은 경우
                
                // 패턴이 . 인 경우

                // 두 문자가 다른 경우
            }

            return false;
        }
    }
}
