package sm;

import java.io.*;

public class Number3 {
    private static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[][] boards = new int[N][N];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            String[] numbers = line.split(" ");
            for (int j = 0; j < numbers.length; j++) {
                boards[i][j] = Integer.parseInt(numbers[j]);
            }
        }

        dfs(boards, N * N, N, N, 0);
        bw.write(String.valueOf(answer));

        bw.flush();
        br.close();
        bw.close();
    }

    private static void dfs(int[][] boards, int size, int row, int column, int max) {
        if (size == 1) {
            if (answer < max) {
                answer = max;
            }
            return;
        }

        int[][] newBoards;
        int[][] anotherBoards;
        int maxInBoards;
        if (column / 2 > 0) {
            // 왼쪽
            newBoards = new int[row][column / 2];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column / 2; j++) {
                    newBoards[i][j] = boards[i][j];
                }
            }
            maxInBoards = getMax(newBoards);
            anotherBoards = new int[row][column / 2];
            for (int i = 0; i < row; i++) {
                int addIndex = column / 2;
                for (int j = 0; j < column / 2; j++) {
                    anotherBoards[i][j] = boards[i][j + addIndex];
                }
            }
            dfs(anotherBoards, size / 2, row, column / 2, max + maxInBoards);

            // 오른쪽
            newBoards = new int[row][column / 2];
            for (int i = 0; i < row; i++) {
                int addIndex = column / 2;
                for (int j = 0; j < column / 2; j++) {
                    newBoards[i][j] = boards[i][j + addIndex];
                }
            }
            anotherBoards = new int[row][column / 2];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column / 2; j++) {
                    anotherBoards[i][j] = boards[i][j];
                }
            }
            maxInBoards = getMax(newBoards);
            dfs(anotherBoards, size / 2, row, column / 2, max + maxInBoards);
        }

        if (row / 2 > 0) {
            // 아래쪽
            newBoards = new int[row / 2][column];
            for (int i = 0; i < row / 2; i++) {
                int addIndex = row / 2;
                for (int j = 0; j < column; j++) {
                    newBoards[i][j] = boards[i + addIndex][j];
                }
            }
            maxInBoards = getMax(newBoards);
            anotherBoards = new int[row / 2][column];
            for (int i = 0; i < row / 2; i++) {
                for (int j = 0; j < column; j++) {
                    anotherBoards[i][j] = boards[i][j];
                }
            }
            dfs(anotherBoards, size / 2, row / 2, column, max + maxInBoards);

            // 위쪽
            newBoards = new int[row / 2][column];
            for (int i = 0; i < row / 2; i++) {
                for (int j = 0; j < column; j++) {
                    newBoards[i][j] = boards[i][j];
                }
            }
            maxInBoards = getMax(newBoards);
            anotherBoards = new int[row / 2][column];
            for (int i = 0; i < row / 2; i++) {
                int addIndex = row / 2;
                for (int j = 0; j < column; j++) {
                    anotherBoards[i][j] = boards[i + addIndex][j];
                }
            }
            dfs(anotherBoards, size / 2, row / 2, column, max + maxInBoards);
        }
    }

    private static int getMax(int[][] leftBoards) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < leftBoards.length; i++) {
            for (int j = 0; j < leftBoards[i].length; j++) {
                if (max < leftBoards[i][j]) {
                    max = leftBoards[i][j];
                }
            }
        }
        return max;
    }
}
