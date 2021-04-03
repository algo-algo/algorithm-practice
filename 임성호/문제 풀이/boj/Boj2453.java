package boj;

import java.io.*;

public class Boj2453 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int i = 0; i < 5; i++) {
            String standard = bf.readLine();
            String[] connection = standard.split(" ");
            int N = Integer.parseInt(connection[0]);
            int M = Integer.parseInt(connection[1]);
            for (int j = 0; j < M; j++) {
                String line = bf.readLine();
                String[] lines = line.split(" ");
                int relation = Integer.parseInt(lines[0]);
                int x = Integer.parseInt(lines[1]);
                int y = Integer.parseInt(lines[2]);
            }
        }

        bw.flush();
        bf.close();
        bw.close();
    }


}
