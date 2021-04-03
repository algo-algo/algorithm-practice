package sw;

import java.io.FileInputStream;
import java.util.Scanner;

public class Num4014 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/4014_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int N = sc.nextInt();
                int X = sc.nextInt();

                int[][] grounds = new int[N][N];
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        grounds[i][j] = sc.nextInt();
                    }
                }

                int answer = 0;

                for (int i = 0; i < N; i++) {
                    int[] horizontalGround = grounds[i];

                    if (isRunway(N, X, horizontalGround)) {
                        answer++;
                    }
                }

                for (int i = 0; i < N; i++) {
                    int[] verticalGround = new int[N];
                    for (int j = 0; j < N; j++) {
                        verticalGround[j] = grounds[j][i];
                    }

                    if (isRunway(N, X, verticalGround)) {
                        answer++;
                    }
                }

                System.out.println("#" + test_case + " " + answer);
            }
        }

        private static boolean isRunway(int N, int X, int[] ground) {
            int nowGround = 0;
            int groundCount = 0;
            int positiveCount = 0;

            for (int j = 0; j < N; j++) {
                if (nowGround == 0) {
                    nowGround = ground[j];
                    groundCount++;
                    positiveCount++;
                    continue;
                }

                if (nowGround == ground[j]) {
                    groundCount++;
                    positiveCount++;
                } else {
                    if (nowGround - ground[j] == -1) {
                        if (positiveCount >= X) {
                            nowGround = ground[j];
                            groundCount++;
                            positiveCount = 1;
                        } else {
                            break;
                        }
                    } else if (nowGround - ground[j] == 1) {
                        int negativeCount = 1;
                        int negativeIndex = j + 1;
                        for (; negativeIndex < N; negativeIndex++) {
                            if (ground[j] == ground[negativeIndex]) {
                                negativeCount++;
                                if (negativeCount >= X) {
                                    j = negativeIndex;
                                    nowGround = ground[negativeIndex];
                                    groundCount += negativeCount;
                                    positiveCount = 0;
                                    break;
                                }
                            } else {
                                break;
                            }
                        }

                        if (negativeIndex != j) {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }

            return groundCount == N;
        }
    }
}
