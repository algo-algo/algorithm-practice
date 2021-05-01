package boj;

import java.io.*;

public class Boj14216 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        int[][] costs = new int[N][N];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            String[] cost = line.split(" ");
            for (int j = 0; j < N; j++) {
                costs[i][j] = Integer.parseInt(cost[j]);
            }
        }

        System.out.println("hi");
    }


}
