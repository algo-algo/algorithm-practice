package boj;

import java.io.*;
import java.util.Arrays;

public class Boj1655 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        MinHeap minHeap = new MinHeap();
        for (int i = 1; i <= N; i++) {
            int number = Integer.parseInt(br.readLine());
            minHeap.add(number, i - 1);
            int index = 0;
            if (i % 2 == 0) {
                index = (i / 2) - 1;
            } else {
                index = i / 2;
            }

            bw.write(String.valueOf(minHeap.minHeap[index]) + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }

    static class MinHeap {
        private final Integer[] minHeap = new Integer[100_000];

        public void add(Integer number, int index) {
            minHeap[index] = number;
            int heapSize = index;

            while (heapSize > 0 && minHeap[heapSize / 2] > minHeap[heapSize]) {
                int temp = minHeap[heapSize / 2];
                minHeap[heapSize / 2] = number;
                minHeap[heapSize] = temp;

                heapSize = heapSize / 2;
            }

            if (heapSize != index) {
                Arrays.sort(minHeap, heapSize, index);
            }
        }
    }
}
