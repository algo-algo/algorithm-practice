package sw;

import java.io.FileInputStream;
import java.util.Scanner;

public class Num2983 {
    static class Solution {
        public static void main(String args[]) throws Exception {

            System.setIn(new FileInputStream("src/sw/res/2983_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int L = sc.nextInt();

                sc.nextLine();
                String line = sc.nextLine();
                int answer = 0;
                for (int i = 1; i <= L; i++) {
                    for (int index = 0; i + index < L; index++) {
                        String subString = line.substring(index, i + index);
                        int patternLength = subString.length();
                        int boyerMoore = boyerMoore(line, subString);
                        if (boyerMoore >= 2 && patternLength > answer) {
                            answer = patternLength;
                        }
                    }
                }

                System.out.println("#" + test_case + " " + answer);
            }
        }

        private static int boyerMoore(String text, String pattern) {
            int textCursor;
            int patternCursor;
            int textLen = text.length();
            int n = pattern.length();
            int[] skipTable = new int[200001];

            for (textCursor = 0; textCursor <= Character.MAX_VALUE; textCursor++) {
                skipTable[textCursor] = n;
            }
            for (textCursor = 0; textCursor < n - 1; textCursor++) {
                skipTable[pattern.charAt(textCursor)] = n - textCursor - 1;
            }

            int patternCount = 0;
            while (textCursor < textLen) {
                patternCursor = n - 1;

                while (text.charAt(textCursor) == pattern.charAt(patternCursor)) {
                    if (patternCursor == 0) {
                        patternCount += 1;
                        break;
                    }
                    patternCursor--;
                    textCursor--;
                }
                textCursor += Math.max(skipTable[text.charAt(textCursor)], n - patternCursor);
            }

            return patternCount;
        }
    }
}
