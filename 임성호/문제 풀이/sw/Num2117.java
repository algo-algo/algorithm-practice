package sw;

import java.io.FileInputStream;
import java.util.*;

public class Num2117 {
    private static int N;

    public static void main(String args[]) throws Exception {
        System.setIn(new FileInputStream("src/sw/res/test.txt"));

        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        int[] costs = new int[46];
        for (int i = 1; i <= 45; i++) {
            costs[i] = (i * i) + ((i - 1) * (i - 1));
        }

        for (int test_case = 1; test_case <= T; test_case++) {
            N = sc.nextInt();
            int M = sc.nextInt();

            Board[][] boards = new Board[N][N];
            int allHomes = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int board = sc.nextInt();
                    boards[i][j] = new Board(i, j);
                    if (board == 1) {
                        allHomes++;
                        boards[i][j].home();
                    }
                }
            }

            int maximumK = 0;
            int maximumProfit = M * allHomes;
            for (int i = 0; i < costs.length; i++) {
                if (costs[i] > maximumProfit) {
                    maximumK = i - 1;
                    break;
                }
            }

            int maximumHomeCount = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    // 모든 보드 칸마다 최대 k 값 만큼 bfs로 칸을 색칠해서 이득이 되는지 계산한다.
                    int k = 1;
                    Queue<Board> queue = new LinkedList<>();

                    queue.add(boards[i][j]);
                    boards[i][j].visit();
                    int homeCount = boards[i][j].isHome() ? 1 : 0;

                    int neighborCount = 0;
                    int lossNeighborCount = 0;

                    while (k != maximumK) {
                        Queue<Board> newQueue = bfs(queue, boards);
                        neighborCount = (int) newQueue.stream()
                                .filter(Board::isHome)
                                .count();

                        int securityProfit = ((neighborCount + homeCount + lossNeighborCount) * M) - costs[++k];
                        if (securityProfit > 0) {
                            homeCount += neighborCount + lossNeighborCount;
                            lossNeighborCount = 0;
                        } else {
                            lossNeighborCount = neighborCount;
                        }
                        queue = newQueue;
//                        printBoard(boards);
                    }

                    initBoards(boards);
                    if (homeCount >= maximumHomeCount) {
                        System.out.println("i: " + i + ", j: " + j + ", home count: " + homeCount);
                        maximumHomeCount = homeCount;
                    }
                }
            }
            System.out.println("#" + test_case + " " + maximumHomeCount);
        }
    }

    private static void printBoard(Board[][] boards) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int visit = boards[i][j].isVisited ? 1 : 0;
                System.out.print(visit + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private static Queue<Board> bfs(Queue<Board> queue, Board[][] boards) {
        Queue<Board> newQueue = new LinkedList<>();

        while (!queue.isEmpty()) {
            Board board = queue.poll();
            int row = board.getRow();
            int column = board.getColumn();

            // 위쪽. 방문하지 않았다면
            if (row - 1 >= 0 && boards[row - 1][column].isNotVisited()) {
                newQueue.add(boards[row - 1][column]);
                boards[row - 1][column].visit();
            }
            // 아래쪽. 방문하지 않았다면
            if (row + 1 < N && boards[row + 1][column].isNotVisited()) {
                newQueue.add(boards[row + 1][column]);
                boards[row + 1][column].visit();
            }
            // 오른쪽. 방문하지 않았다면
            if (column + 1 < N && boards[row][column + 1].isNotVisited()) {
                newQueue.add(boards[row][column + 1]);
                boards[row][column + 1].visit();
            }
            // 왼쪽. 방문하지 않았다면
            if (column - 1 >= 0 && boards[row][column - 1].isNotVisited()) {
                newQueue.add(boards[row][column - 1]);
                boards[row][column - 1].visit();
            }
        }

        return newQueue;
    }

    private static void initBoards(Board[][] boards) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                boards[i][j].initBoard();
            }
        }
    }

    static class Board {
        private final int row;
        private final int column;
        private boolean isVisited;
        private boolean isHome;

        public Board(int row, int column) {
            this.row = row;
            this.column = column;
            this.isVisited = false;
            this.isHome = false;
        }

        public void visit() {
            this.isVisited = true;
        }

        public void home() {
            this.isHome = true;
        }

        public boolean isNotVisited() {
            return !isVisited;
        }

        public boolean isHome() {
            return isHome;
        }

        public void initBoard() {
            this.isVisited = false;
        }

        public int getRow() {
            return row;
        }

        public int getColumn() {
            return column;
        }
    }
}
