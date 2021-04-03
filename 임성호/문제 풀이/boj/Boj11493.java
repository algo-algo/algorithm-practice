package boj;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Boj11493 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int testCase = 0; testCase < T; testCase++) {
            String line = br.readLine();
            String[] lines = line.split(" ");
            int n = Integer.parseInt(lines[0]);
            int m = Integer.parseInt(lines[1]);

            Graph graph = new Graph(n);
            for (int i = 0; i < m; i++) {
                line = br.readLine();
                lines = line.split(" ");
                graph.addEdge(Integer.parseInt(lines[0]), Integer.parseInt(lines[1]), 1);
            }

            String color = br.readLine();
            String[] colors = color.split(" ");
            String coin = br.readLine();
            String[] coins = coin.split(" ");
            List<Integer> differentIndexes = new ArrayList<>();
            for (int i = 0; i < colors.length; i++) {
                if (!colors[i].equals(coins[i])) {
                    differentIndexes.add(i + 1);
                }
            }

            int halfSize = differentIndexes.size() / 2;
            int[][] graphForDfs = new int[halfSize][halfSize];
            for (int i = 0; i < halfSize; i++) {
                int index = differentIndexes.get(i);
                int[] distance = graph.getDistance(index);
                for (int j = 0; j < halfSize; j++) {
                    int targetIndex = differentIndexes.get(j + halfSize);
                    graphForDfs[i][j] = distance[targetIndex];
                }
            }

            boolean[] check = new boolean[graphForDfs.length];
            int[] min = {Integer.MAX_VALUE};
            dfs(graphForDfs, check, min, 0, 0, 0);
            bw.write(String.valueOf(min[0]) + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }

    private static void dfs(int[][] graphForDfs, boolean[] check, int[] min, int count, int candidate, int row) {
        if (count == check.length) {
            if (candidate < min[0]) {
                min[0] = candidate;
            }
            return;
        }

        for (int i = 0; i < graphForDfs.length; i++) {
            if (!check[i]) {
                int number = graphForDfs[row][i];
                check[i] = true;
                dfs(graphForDfs, check, min, count + 1, candidate + number, row + 1);
                check[i] = false;
            }
        }
    }

    static class Graph {
        class Edge {
            private int vertex;
            private int weight;

            public Edge(int vertex, int weight) {
                this.vertex = vertex;
                this.weight = weight;
            }
        }

        private List<Edge>[] graph;

        public Graph(int n) {
            this.graph = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) {
                this.graph[i] = new ArrayList<>();
            }
        }

        public void addEdge(int start, int end, int weight) {
            graph[start].add(new Edge(end, weight));
        }

        public int[] getDistance(int source) {
            int[] distance = new int[graph.length];

            boolean[] inQueue = new boolean[graph.length];
            Queue<Integer> queue = new LinkedList<>();
            for (int i = 1; i < distance.length; i++) {
                distance[i] = Integer.MAX_VALUE;
            }
            distance[source] = 0;

            queue.add(source);
            inQueue[source] = true;

            while (!queue.isEmpty()) {
                int target = queue.remove();
                inQueue[target] = false;
                for (Edge edge : this.graph[target]) {
                    int vertex = edge.vertex;
                    int weight = edge.weight;
                    if (distance[vertex] > distance[target] + weight) {
                        distance[vertex] = distance[target] + weight;
                        if (!inQueue[vertex]) {
                            queue.add(vertex);
                            inQueue[vertex] = true;
                        }
                    }
                }
            }
            return distance;
        }
    }
}

