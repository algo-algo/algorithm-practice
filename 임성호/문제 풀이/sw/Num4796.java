package sw;

import java.io.FileInputStream;
import java.util.Scanner;

public class Num4796 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/4796_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int N = sc.nextInt();

                int[] heights = new int[N];
                for (int i = 0; i < N; i++) {
                    heights[i] = sc.nextInt();
                }

                int[] count = {0};
                int[] indexes = {0, 0};
                int[] maxHeight = {0, 0};
                int[] minHeight = {0, 0};

                while (indexes[0] < N) {
                    if (indexes[1] < N && indexes[0] == indexes[1]) {
                        indexes[1]++;
                    } else if (indexes[1] < N && heights[indexes[0]] > heights[indexes[1]]) {
                        indexes[0]++;
                    } else if (indexes[1] < N && heights[indexes[0]] < heights[indexes[1]]) {
                        getMaxHeight(heights, indexes, maxHeight);
                        getMinHeight(heights, indexes, minHeight);
                        getCount(indexes, maxHeight, minHeight, count);
                    } else if (indexes[1] >= N) {
                        indexes[0]++;
                    }
                }

                System.out.println("#" + test_case + " " + count[0]);
            }
        }

        private static void getCount(int[] indexes, int[] maxHeight, int[] minHeight, int[] count) {
            int leftCount = maxHeight[1] - indexes[0];
            int rightCount = minHeight[1] - maxHeight[1];
            count[0] += (leftCount * rightCount);
            indexes[0] = maxHeight[1];
        }

        private static void getMinHeight(int[] heights, int[] indexes, int[] minHeight) {
            if (indexes[1] + 1 < heights.length) {
                int minIndex = indexes[1] + 1;
                minHeight[0] = heights[minIndex];
                while (true) {
                    if (minIndex + 1 < heights.length) {
                        if (minHeight[0] > heights[minIndex + 1]) {
                            minHeight[0] = heights[minIndex + 1];
                            minIndex++;
                        } else {
                            minHeight[1] = minIndex;
                            break;
                        }
                    } else {
                        minHeight[1] = minIndex;
                        break;
                    }
                }
            } else {
                minHeight[1] = indexes[1];
            }
        }

        private static void getMaxHeight(int[] heights, int[] indexes, int[] maxHeight) {
            maxHeight[0] = heights[indexes[1]];
            while (true) {
                if (indexes[1] + 1 < heights.length) {
                    if (maxHeight[0] < heights[indexes[1] + 1]) {
                        maxHeight[0] = heights[indexes[1] + 1];
                        indexes[1]++;
                    } else {
                        maxHeight[1] = indexes[1];
                        break;
                    }
                } else {
                    maxHeight[1] = indexes[1];
                    break;
                }
            }
        }
    }
}
