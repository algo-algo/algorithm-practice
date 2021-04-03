package boj;

import java.io.*;

public class Boj1133 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = br.readLine();
        String[] lines = line.split(" ");
        int K = Integer.parseInt(lines[0]);
        int N = Integer.parseInt(lines[1]);
        int A = Integer.parseInt(lines[2]);

        char[] alphabets = new char[26];
        for (int i = 0; i < 26; i++) {
            alphabets[i] = (char) (65 + i);
        }

        int alphabetIndex = 0;
        String answer = "";
    }

    private static void dfs(String answer, int K, int A) {
        if (answer.length() == K) {

        } else {
            for (int i = 0; i < A; i++) {

            }
        }
    }
}
