package boj;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Boj3008 {
    private static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        List<Point> points = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            String[] numbers = line.split(" ");
            points.add(new Point(Integer.parseInt(numbers[0]), Integer.parseInt(numbers[1])));
        }

        List<Point> targetPoints = new ArrayList<>();
        for (int i = 0; i < N - 2; i++) {
            targetPoints.add(points.get(i));
            for (int j = i + 1; j < N - 1; j++) {
                targetPoints.add(points.get(j));
                for (int k = j + 1; k < N; k++) {
                    targetPoints.add(points.get(k));
                    if (isRightTriangle(targetPoints)) {
                        answer++;
                    }
                    targetPoints.remove(points.get(k));
                }
                targetPoints.remove(points.get(j));
            }
            targetPoints.remove(points.get(i));
        }

        bw.write(String.valueOf(answer));

        bw.flush();
        br.close();
        bw.close();
    }

    static class Point {
        private final int x;
        private final int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public static int calculatePowerLength(Point p1, Point p2) {
            double x = Math.pow(Math.abs(p1.x - p2.x), 2);
            double y = Math.pow(Math.abs(p1.y - p2.y), 2);

            return (int) (x + y);
        }
    }

    private static boolean isRightTriangle(List<Point> targetPoints) {
        List<Integer> lengths = Arrays.asList(
                Point.calculatePowerLength(targetPoints.get(0), targetPoints.get(1)),
                Point.calculatePowerLength(targetPoints.get(0), targetPoints.get(2)),
                Point.calculatePowerLength(targetPoints.get(1), targetPoints.get(2))
        );
        Collections.sort(lengths);

        return lengths.get(0) + lengths.get(1) == lengths.get(2);
    }
}
