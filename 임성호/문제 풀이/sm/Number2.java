package sm;

import java.io.*;

public class Number2 {
    public static void main(String[] args) throws IOException  {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] steps = new int[N];
        String line = br.readLine();
        String[] lineNumbers = line.split(" ");
        for (int i = 0; i < lineNumbers.length; i++) {
            steps[i] = Integer.parseInt(lineNumbers[i]);
        }

        int answer = Integer.MIN_VALUE;
        for (int i = 0; i < steps.length; i++) {
            boolean[] stepChecks = new boolean[N];
            int infiniteLength = compare(steps, stepChecks, i);
            if (infiniteLength >= answer) {
                answer = infiniteLength;
            }
        }

        bw.write(Integer.toString(answer));
        bw.flush();
        br.close();
        bw.close();
    }

    private static int compare(int[] steps, boolean[] stepChecks, int index) {
        int length = 0;
        stepChecks[index] = true;
        int repeatIndex = index;
        boolean isCheck = false;
        while (true) {
            index = steps[index] + index;
            if (repeatIndex != index) {
                if (stepChecks[index] && !isCheck) {
                    repeatIndex = index;
                    isCheck = true;
                    length++;
                } else if (stepChecks[index]) {
                    length++;
                }
                stepChecks[index] = true;
            } else {
                break;
            }
        }

        return length;
    }
}
