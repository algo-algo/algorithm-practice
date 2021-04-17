package boj;

import java.io.*;
import java.util.*;

public class Boj1854 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = br.readLine();
        String[] lines = line.split(" ");
        int n = Integer.parseInt(lines[0]);
        int m = Integer.parseInt(lines[1]);
        int k = Integer.parseInt(lines[2]);

        List<City> cities = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            cities.add(new City());
        }
        for (int i = 0; i < m; i++) {
            line = br.readLine();
            lines = line.split(" ");
            int a = Integer.parseInt(lines[0]) - 1;
            int b = Integer.parseInt(lines[1]) - 1;
            int c = Integer.parseInt(lines[2]);
            City city = cities.get(a);
            city.addEdge(a, b, c);
        }

        dijkstra(bw, cities, n, k);

        bw.flush();
        br.close();
        bw.close();
    }

    private static void dijkstra(BufferedWriter bw, List<City> cities, int n, int k) throws IOException {
        int[] distance = new int[n];
        distance[0] = 0;
        for (int i = 1; i < n; i++) {
            distance[i] = Integer.MAX_VALUE;
        }

        PriorityQueue<Edge> queue = new PriorityQueue<>();
        queue.addAll(cities.get(0).edges);
        cities.get(0).visit();

        // 도시의 방문 횟수가 아닌 도시의 최단 거리 값이 바뀐 횟수로 체크해야 한다.
        while (!queue.isEmpty()) {
            Edge edge = queue.remove();
            City city = cities.get(edge.end);
            if (city.visitCount < k) {
                int calculateScore = distance[edge.start] + edge.score;
                if (calculateScore < distance[edge.end]) {
                    distance[edge.end] = calculateScore;
                    if (city.visitCount == 0) {
                        queue.addAll(city.edges);
                    }
                    city.visit();
                }
            }
        }

        for (int i = 0; i < cities.size(); i++) {
            City city = cities.get(i);
            if (city.visitCount >= k) {
                bw.write(String.valueOf(distance[i]) + "\n");
            } else {
                bw.write(String.valueOf(-1) + "\n");
            }
        }
    }

    static class City {
        private int visitCount;
        private final List<Edge> edges;

        public City() {
            this.visitCount = 0;
            this.edges = new ArrayList<>();
        }

        public void addEdge(int start, int end, int score) {
            edges.add(new Edge(start, end, score));
        }

        public void visit() {
            visitCount++;
        }
    }

    static class Edge implements Comparable<Edge> {
        private final int start;
        private final int end;
        private final int score;

        public Edge(int start, int end, int score) {
            this.start = start;
            this.end = end;
            this.score = score;
        }

        @Override
        public int compareTo(Edge edge) {
            if (this.score < edge.score) {
                return -1;
            } else if (this.score == edge.score) {
                return 0;
            }
            return 1;
        }
    }
}
