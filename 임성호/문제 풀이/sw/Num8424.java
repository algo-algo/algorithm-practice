package sw;

import java.io.FileInputStream;
import java.util.*;

public class Num8424 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/8424_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int n = sc.nextInt();

                List<List<Integer>> cities = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    cities.add(new ArrayList<>());
                }

                int[] edges = new int[n];
                for (int i = 0; i < n; i++) {
                    int start = sc.nextInt() - 1;
                    int end = sc.nextInt() - 1;
                    cities.get(start).add(end);
                    cities.get(end).add(start);
                    edges[start]++;
                    edges[end]++;
                }

                boolean[] visited = new boolean[n];
                Queue<Integer> queue = new LinkedList<>();
                int nonCycle = 0;
                for (int i = 0; i < n; i++) {
                    if (!visited[i] && edges[i] == 1) {
                        queue.add(i);
                        while (!queue.isEmpty()) {
                            int node = queue.poll();
                            if (!visited[node] && edges[node] == 1) {
                                visited[node] = true;
                                nonCycle++;
                                for (int nextNode : cities.get(node)) {
                                    edges[nextNode]--;
                                    queue.add(nextNode);
                                }
                            }
                        }
                    }
                }

                System.out.println("#" + test_case + " " + (n - nonCycle));
            }
        }
    }
}
