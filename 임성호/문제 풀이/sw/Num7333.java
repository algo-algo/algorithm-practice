package sw;

import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Num7333 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/7333_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int N = sc.nextInt();
                int[] weights = new int[N];
                for (int i = 0; i < N; i++) {
                    weights[i] = sc.nextInt();
                }
                Arrays.sort(weights);

                int answer = 0;
                int front = 0;
                int end = N - 1;
                while (front <= end) {
                    int weight = weights[end];
                    int needBoxCount = getNeedBoxCount(weight) - 1;
                    if (needBoxCount > N - ((N - end) + front)) {
                        break;
                    }
                    end--;
                    front += needBoxCount;
                    answer++;
                }

                System.out.println("#" + test_case + " " + answer);
            }
        }

        private static int getNeedBoxCount(int weight) {
            int quotient = 50 / weight;
            int remainder = 50 % weight;
            if (remainder != 0) {
                quotient++;
            }

            return quotient;
        }
    }
}
