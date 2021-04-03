package sw;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Num1258 {
    static class Solution {
        public static void main(String args[]) throws Exception {

            System.setIn(new FileInputStream("src/sw/res/1258_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int n = sc.nextInt();
                Board[][] boards = new Board[n][n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int material = sc.nextInt();
                        boards[i][j] = new Board(material);
                    }
                }

                List<Answer> answers = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (!boards[i][j].isVisit && boards[i][j].isNotEmpty()) {
                            getAnswer(answers, boards, n, i, j);
                        }
                    }
                }

                Collections.sort(answers);
                System.out.print("#" + test_case + " " + answers.size());
                answers.forEach(System.out::print);
                System.out.println();
            }
        }

        private static void getAnswer(List<Answer> answers, Board[][] boards, int n, int row, int column) {
            int i;
            int j;
            for (i = row; i < n; i++) {
                if (!boards[i][column].isVisit && boards[i][column].isNotEmpty()) {
                    boards[i][column].visit();
                } else if (!boards[i][column].isNotEmpty()) {
                    break;
                }
            }
            for (j = column + 1; j < n; j++) {
                if (!boards[row][j].isVisit && boards[row][j].isNotEmpty()) {
                    boards[row][j].visit();
                } else if (!boards[row][j].isNotEmpty()) {
                    break;
                }
            }
            answers.add(new Answer(i - row, j - column));
            visitBoard(boards, row + 1, i, column + 1, j);
        }

        private static void visitBoard(Board[][] boards, int rowStart, int rowEnd, int columnStart, int columnEnd) {
            for (int i = rowStart; i < rowEnd; i++) {
                for (int j = columnStart; j < columnEnd; j++) {
                    boards[i][j].visit();
                }
            }
        }

        static class Board {
            private final int material;
            private boolean isVisit;

            public Board(int material) {
                this.material = material;
                isVisit = false;
            }

            public void visit() {
                this.isVisit = true;
            }

            public boolean isNotEmpty() {
                return material != 0;
            }
        }

        static class Answer implements Comparable<Answer> {
            private final int row;
            private final int column;

            public Answer(int row, int column) {
                this.row = row;
                this.column = column;
            }

            @Override
            public int compareTo(Answer answer) {
                if (this.row * this.column < answer.row * answer.column) {
                    return -1;
                }
                if (this.row * this.column == answer.row * answer.column) {
                    if (this.row < answer.row) {
                        return -1;
                    }
                    if (this.row == answer.row) {
                        return 0;
                    }
                }
                return 1;
            }

            @Override
            public String toString() {
                return " " + this.row + " " + this.column;
            }
        }
    }
}
