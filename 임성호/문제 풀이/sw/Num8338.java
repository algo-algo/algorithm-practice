package sw;

import java.io.FileInputStream;
import java.util.Scanner;

public class Num8338 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/8338_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int n = sc.nextInt();
                int[] numbers = new int[n];
                for (int i = 0; i < n; i++) {
                    numbers[i] = sc.nextInt();
                }

                int left = numbers[0];
                for (int index = 1; index < n; index++) {
                    int right = numbers[index];
                    int sum = left + right;
                    int multiple = left * right;
                    left = Math.max(sum, multiple);
                }
                System.out.println("#" + test_case + " " + left);
            }
        }
    }
}
