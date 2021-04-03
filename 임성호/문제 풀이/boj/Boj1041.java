package boj;

import java.io.*;
import java.util.Arrays;
import java.util.List;

public class Boj1041 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long N = Long.parseLong(bf.readLine());
        String line = bf.readLine();
        String[] lineNumbers = line.split(" ");
        int[] diceNumbers = Arrays.stream(lineNumbers)
                .mapToInt(Integer::parseInt)
                .toArray();

        if (N == 1) {
            int max = Arrays.stream(diceNumbers)
                    .max()
                    .orElse(-1);
            int answer = Arrays.stream(diceNumbers)
                    .sum() - max;
            bw.write(String.valueOf(answer));
        } else {
            long threeShapeMinimum = getThreeShapeMinimum(diceNumbers);
            long twoShapeMinimum = getTwoShapeMinimum(diceNumbers);
            long oneShapeMinimum = Arrays.stream(diceNumbers)
                    .min()
                    .orElse(-1);

            long answer = threeShapeMinimum * 4; // 상단 귀퉁이
            answer += twoShapeMinimum * 4; // 하단 귀퉁이
            answer += (N - 2) * 8 * twoShapeMinimum;
            answer += (N - 2) * 4 * oneShapeMinimum;
            answer += (((N * N) - (((N - 2) * 4) + 4)) * oneShapeMinimum) * 5;

            System.out.println(answer);
        }

        bw.flush();
        bf.close();
        bw.close();
    }

    private static long getThreeShapeMinimum(int[] diceNumbers) {
        List<Integer> threeShapeSums = Arrays.asList(
                diceNumbers[0] + diceNumbers[1] + diceNumbers[2],
                diceNumbers[0] + diceNumbers[1] + diceNumbers[3],
                diceNumbers[0] + diceNumbers[2] + diceNumbers[4],
                diceNumbers[0] + diceNumbers[3] + diceNumbers[4],
                diceNumbers[5] + diceNumbers[1] + diceNumbers[2],
                diceNumbers[5] + diceNumbers[1] + diceNumbers[3],
                diceNumbers[5] + diceNumbers[2] + diceNumbers[4],
                diceNumbers[5] + diceNumbers[3] + diceNumbers[4]
        );

        return (long) threeShapeSums.stream()
                .min(Integer::compare)
                .orElse(-1);
    }

    private static long getTwoShapeMinimum(int[] diceNumbers) {
        List<Integer> twoShapeSums = Arrays.asList(
                diceNumbers[0] + diceNumbers[1],
                diceNumbers[0] + diceNumbers[2],
                diceNumbers[0] + diceNumbers[3],
                diceNumbers[0] + diceNumbers[4],
                diceNumbers[5] + diceNumbers[1],
                diceNumbers[5] + diceNumbers[2],
                diceNumbers[5] + diceNumbers[3],
                diceNumbers[5] + diceNumbers[4]
        );

        return (long) twoShapeSums.stream()
                .min(Integer::compare)
                .orElse(-1);
    }
}
