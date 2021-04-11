package sw;

import java.io.FileInputStream;
import java.util.Scanner;

public class Num4112 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/4112_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            Pyramid pyramid = new Pyramid();

            for (int test_case = 1; test_case <= T; test_case++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;

                int answer = 0;
                Coordinate start = pyramid.getCoordinate(a);
                Coordinate end = pyramid.getCoordinate(b);
                int height = Math.abs(start.x - end.x);
                Coordinate leftEdge = new Coordinate(0, 0);
                Coordinate rightEdge = new Coordinate(0, 0);
                if (a < b) {
                    leftEdge = new Coordinate(start.x + height, start.y);
                    rightEdge = new Coordinate(start.x + height, start.y + height);
                } else if (a > b) {
                    // 역삼각형 모양
                    leftEdge = new Coordinate(start.x - height, start.y - height);
                    rightEdge = new Coordinate(start.x - height, start.y);
                } else {
                    leftEdge = start;
                    rightEdge = end;
                }
                if (leftEdge.y <= end.y && end.y <= rightEdge.y) {
                    answer = height;
                } else if (end.y < leftEdge.y) {
                    answer = height + (leftEdge.y - end.y);
                } else  {
                    answer = height + (end.y - rightEdge.y);
                }

                System.out.println("#" + test_case + " " + answer);
            }
        }

        static class Coordinate {
            private final int x;
            private final int y;

            public Coordinate(int x, int y) {
                this.x = x;
                this.y = y;
            }
        }

        static class Pyramid {
            private final Coordinate[] pyramid = new Coordinate[10_000];

            public Pyramid() {
                initPyramid();
            }

            private void initPyramid() {
                int index = 0;
                int oldIndex = 1;
                for (int i = 1; i <= 141; i++) {
                    int range = (i * (i + 1)) / 2;
                    int y = 1;
                    if (i != 141) {
                        for (int j = oldIndex; j <= range; j++) {
                            pyramid[index] = new Coordinate(i, y);
                            index += 1;
                            y += 1;
                        }
                        oldIndex = range + 1;
                    } else {
                        for (int j = oldIndex; j <= 10_000; j++) {
                            pyramid[index] = new Coordinate(i, y);
                            index += 1;
                            y += 1;
                        }
                    }
                }
            }

            public Coordinate getCoordinate(int index) {
                return pyramid[index];
            }
        }
    }
}
