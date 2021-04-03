package sw;

import java.io.FileInputStream;
import java.util.Scanner;

public class Num4013 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/4013_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int K = sc.nextInt();

                int[][] magnets = new int[4][8];

                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 8; j++) {
                        magnets[i][j] = sc.nextInt();
                    }
                }

                for (int i = 0; i < K; i++) {
                    int magnetIndex = sc.nextInt() - 1;
                    int direction = sc.nextInt();
                    boolean isRotate;

                    if (magnetIndex == 0) {
                        rotate(magnets[magnetIndex], direction);
                        isRotate = magnets[magnetIndex][2 + direction] != magnets[magnetIndex + 1][6];
                        if (isRotate) {
                            direction = direction * -1;
                            magnetIndex = magnetIndex + 1;
                            rotate(magnets[magnetIndex], direction);
                            isRotate = magnets[magnetIndex][2 + direction] != magnets[magnetIndex + 1][6];
                            if (isRotate) {
                                direction = direction * -1;
                                magnetIndex = magnetIndex + 1;
                                rotate(magnets[magnetIndex], direction);
                                isRotate = magnets[magnetIndex][2 + direction] != magnets[magnetIndex + 1][6];
                                if (isRotate) {
                                    direction = direction * -1;
                                    magnetIndex = magnetIndex + 1;
                                    rotate(magnets[magnetIndex], direction);
                                }
                            }
                        }
                    } else if (magnetIndex == 1) {
                        rotate(magnets[magnetIndex], direction);
                        if (magnets[magnetIndex][6 + direction] != magnets[magnetIndex - 1][2]) {
                            rotate(magnets[magnetIndex - 1], direction * -1);
                        }
                        isRotate = magnets[magnetIndex][2 + direction] != magnets[magnetIndex + 1][6];
                        if (isRotate) {
                            direction = direction * -1;
                            magnetIndex = magnetIndex + 1;
                            rotate(magnets[magnetIndex], direction);
                            isRotate = magnets[magnetIndex][2 + direction] != magnets[magnetIndex + 1][6];
                            if (isRotate) {
                                direction = direction * -1;
                                magnetIndex = magnetIndex + 1;
                                rotate(magnets[magnetIndex], direction);
                            }
                        }
                    } else if (magnetIndex == 2) {
                        rotate(magnets[magnetIndex], direction);
                        if (magnets[magnetIndex][2 + direction] != magnets[magnetIndex + 1][6]) {
                            rotate(magnets[magnetIndex + 1], direction * -1);
                        }
                        isRotate = magnets[magnetIndex][6 + direction] != magnets[magnetIndex - 1][2];
                        if (isRotate) {
                            direction = direction * -1;
                            magnetIndex = magnetIndex - 1;
                            rotate(magnets[magnetIndex], direction);
                            isRotate = magnets[magnetIndex][6 + direction] != magnets[magnetIndex - 1][2];
                            if (isRotate) {
                                direction = direction * -1;
                                magnetIndex = magnetIndex - 1;
                                rotate(magnets[magnetIndex], direction);
                            }
                        }
                    } else if (magnetIndex == 3) {
                        rotate(magnets[magnetIndex], direction);
                        isRotate = magnets[magnetIndex][6 + direction] != magnets[magnetIndex - 1][2];
                        if (isRotate) {
                            direction = direction * -1;
                            magnetIndex = magnetIndex - 1;
                            rotate(magnets[magnetIndex], direction);
                            isRotate = magnets[magnetIndex][6 + direction] != magnets[magnetIndex - 1][2];
                            if (isRotate) {
                                direction = direction * -1;
                                magnetIndex = magnetIndex - 1;
                                rotate(magnets[magnetIndex], direction);
                                isRotate = magnets[magnetIndex][6 + direction] != magnets[magnetIndex - 1][2];
                                if (isRotate) {
                                    direction = direction * -1;
                                    magnetIndex = magnetIndex - 1;
                                    rotate(magnets[magnetIndex], direction);
                                }
                            }
                        }
                    }
                }

                int answer = magnets[0][0]
                        + (magnets[1][0] * 2)
                        + (magnets[2][0] * 4)
                        + (magnets[3][0] * 8);
                System.out.println("#" + test_case + " " + answer);
            }
        }

        private static void rotate(int[] magnet, int direction) {
            if (direction == 1) {
                int temp = magnet[7];
                for (int i = 7; i >= 1; i--) {
                    magnet[i] = magnet[i - 1];
                }
                magnet[0] = temp;
            } else {
                int temp = magnet[0];
                for (int i = 0; i <= 6; i++) {
                    magnet[i] = magnet[i + 1];
                }
                magnet[7] = temp;
            }
        }
    }

}