package sw;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Num2382 {
    private static int N;

    public static void main(String args[]) throws Exception {

        System.setIn(new FileInputStream("src/sw/res/2382_input.txt"));

        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            N = sc.nextInt();
            int M = sc.nextInt();
            int K = sc.nextInt();

            // 실험실 초기화
            Board[][] boards = new Board[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    boards[i][j] = new Board(i, j);
                }
            }

            // 미생물 정보 초기화
            List<Microorganism> microorganisms = new ArrayList<>();
            for (int i = 0; i < K; i++) {
                int row = sc.nextInt();
                int column = sc.nextInt();
                int micro = sc.nextInt();
                int direction = sc.nextInt();
                microorganisms.add(new Microorganism(row, column, micro, direction));
                boards[row][column].addMicroorganism();
            }

            // 시간만큼 미생물들을 움직인다.
            for (int i = 0; i < M; i++) {
                // 미생물을 움직인다.
                // 현재 미생물이 위치한 보드판에 미생물의 개수를 한 개 줄여준다.
                // 움직인 이후 미생물이 위치한 보드판에 미생물의 개수를 한 개 늘려준다.
                microorganisms.forEach(m -> {
                    boards[m.getRow()][m.getColumn()].removeMicroorganism();
                    m.move();
                    boards[m.getRow()][m.getColumn()].addMicroorganism();
                });

                // 같은 칸에서 만난 미생물들이 있는지 찾아서 합친다.
                // 미생물을 합치고 나면 해당 칸에는 미생물이 1개만 남는다.
                for (int j = 1; j < N - 1; j++) {
                    for (int k = 1; k < N - 1; k++) {
                        if (boards[j][k].isCrush()) {
                            boards[j][k].crushMicroorganism(microorganisms);
                        }
                    }
                }

                // 벽에 도달한 미생물들이 있는지 확인한다.
                microorganisms.stream()
                        .filter(Microorganism::isCell)
                        .forEach(Microorganism::end);
            }

            // 모든 시간이 지난 후 모든 미생물들의 남은 수를 구한다.
            int sumMicroorganism = microorganisms.stream()
                    .mapToInt(Microorganism::getMicro)
                    .sum();
            System.out.println("#" + test_case + " " + sumMicroorganism);
        }
    }

    static class Board {
        private final int row;
        private final int column;
        private int microCount = 0;

        public Board(int row, int column) {
            this.row = row;
            this.column = column;
        }

        public void addMicroorganism() {
            microCount++;
        }

        public void removeMicroorganism() {
            microCount--;
        }

        public boolean isCrush() {
            return microCount > 1;
        }

        public void crushMicroorganism(List<Microorganism> microorganisms) {
            microCount = 1;

            List<Microorganism> targetMicroorganisms = microorganisms.stream()
                    .filter(m -> m.isTargetBoard(row, column))
                    .collect(Collectors.toList());
            int maxMicro = 0;
            int direction = 0;
            for (Microorganism targetMicroorganism : targetMicroorganisms) {
                int micro = targetMicroorganism.getMicro();
                if (maxMicro < micro) {
                    maxMicro = micro;
                    direction = targetMicroorganism.getDirection();
                }
            }
            int sumMicro = targetMicroorganisms.stream()
                    .mapToInt(Microorganism::getMicro)
                    .sum();
            microorganisms.removeAll(targetMicroorganisms);
            microorganisms.add(new Microorganism(row, column, sumMicro, direction));
        }
    }

    static class Microorganism {
        private int row;
        private int column;
        private int micro;
        private int direction;

        public Microorganism(int row, int column, int micro, int direction) {
            this.row = row;
            this.column = column;
            this.micro = micro;
            this.direction = direction;
        }

        public void end() {
            micro /= 2;
            switch (direction) {
                case 1:
                    direction = 2;
                    break;
                case 2:
                    direction = 1;
                    break;
                case 3:
                    direction = 4;
                    break;
                case 4:
                    direction = 3;
                    break;
                default:
                    break;
            }
        }

        public void move() {
            switch (direction) {
                case 1:
                    row--;
                    break;
                case 2:
                    row++;
                    break;
                case 3:
                    column--;
                    break;
                case 4:
                    column++;
                    break;
                default:
                    break;
            }
        }

        public boolean isTargetBoard(int row, int column) {
            return this.row == row
                    && this.column == column;
        }

        public boolean isCell() {
            return row == 0 || column == 0
                    || row == N - 1 || column == N - 1;
        }

        public int getRow() {
            return row;
        }

        public int getColumn() {
            return column;
        }

        public int getMicro() {
            return micro;
        }

        public int getDirection() {
            return direction;
        }
    }
}
