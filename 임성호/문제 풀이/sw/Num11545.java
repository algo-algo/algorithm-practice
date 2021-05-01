package sw;

import java.io.FileInputStream;
import java.util.Scanner;

public class Num11545 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/11545_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                String[][] board = new String[4][4];
                int blankCount = 0;
                for (int i = 0; i < 4; i++) {
                    String line = sc.next();
                    String[] lines = line.split("");
                    for (int j = 0; j < 4; j++) {
                        board[i][j] = lines[j];
                        if (lines[j].equals(".")) {
                            blankCount++;
                        }
                    }
                }

                boolean isEmptyBoard = blankCount != 0;
                boolean isOWin = false;
                boolean isXWin = false;

                // 0,0 에서 아래, 오른쪽, 우하각 대각선
                String target = board[0][0];
                // 아래
                if (target.equals("T")) {
                    target = board[1][0];
                    int count = 1;
                    for (int rowIndex = 2; rowIndex < 4; rowIndex++) {
                        if (target.equals(board[rowIndex][0])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int rowIndex = 1; rowIndex < 4; rowIndex++) {
                        if (target.equals(board[rowIndex][0]) || board[rowIndex][0].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }
                // 오른쪽
                target = board[0][0];
                if (target.equals("T")) {
                    target = board[0][1];
                    int count = 1;
                    for (int columnIndex = 2; columnIndex < 4; columnIndex++) {
                        if (target.equals(board[0][columnIndex])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int columnIndex = 1; columnIndex < 4; columnIndex++) {
                        if (target.equals(board[0][columnIndex]) || board[0][columnIndex].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }
                // 대각선
                target = board[0][0];
                if (target.equals("T")) {
                    target = board[1][1];
                    int count = 1;
                    for (int index = 2; index < 4; index++) {
                        if (target.equals(board[index][index])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int index = 1; index < 4; index++) {
                        if (target.equals(board[index][index]) || board[index][index].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }

                // 0,3 에서 좌하각 대각선, 아래
                target = board[0][3];
                // 좌하각 대각선
                if (target.equals("T")) {
                    target = board[1][2];
                    int count = 1;
                    for (int index = 2; index < 4; index++) {
                        if (target.equals(board[index][3 - index])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int index = 1; index < 4; index++) {
                        if (target.equals(board[index][3 - index]) || board[index][3 - index].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }
                // 아래쪽
                target = board[0][3];
                if (target.equals("T")) {
                    target = board[1][3];
                    int count = 1;
                    for (int rowIndex = 2; rowIndex < 4; rowIndex++) {
                        if (target.equals(board[rowIndex][3])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int rowIndex = 1; rowIndex < 4; rowIndex++) {
                        if (target.equals(board[rowIndex][3]) || board[rowIndex][3].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }

                // 0,1 0,2 에서 아래로
                target = board[0][1];
                if (target.equals("T")) {
                    target = board[1][1];
                    int count = 1;
                    for (int rowIndex = 2; rowIndex < 4; rowIndex++) {
                        if (target.equals(board[rowIndex][1])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int rowIndex = 1; rowIndex < 4; rowIndex++) {
                        if (target.equals(board[rowIndex][1]) || board[rowIndex][1].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }
                target = board[0][2];
                if (target.equals("T")) {
                    target = board[1][2];
                    int count = 1;
                    for (int rowIndex = 2; rowIndex < 4; rowIndex++) {
                        if (target.equals(board[rowIndex][2])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int rowIndex = 1; rowIndex < 4; rowIndex++) {
                        if (target.equals(board[rowIndex][2]) || board[rowIndex][2].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }

                // 1,0 2,0 3,0 에서 오른쪽으로
                target = board[1][0];
                if (target.equals("T")) {
                    target = board[1][1];
                    int count = 1;
                    for (int columnIndex = 2; columnIndex < 4; columnIndex++) {
                        if (target.equals(board[1][columnIndex])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int columnIndex = 1; columnIndex < 4; columnIndex++) {
                        if (target.equals(board[1][columnIndex]) || board[1][columnIndex].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }
                target = board[2][0];
                if (target.equals("T")) {
                    target = board[2][1];
                    int count = 1;
                    for (int columnIndex = 2; columnIndex < 4; columnIndex++) {
                        if (target.equals(board[2][columnIndex])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int columnIndex = 1; columnIndex < 4; columnIndex++) {
                        if (target.equals(board[2][columnIndex]) || board[2][columnIndex].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }
                target = board[3][0];
                if (target.equals("T")) {
                    target = board[3][1];
                    int count = 1;
                    for (int columnIndex = 2; columnIndex < 4; columnIndex++) {
                        if (target.equals(board[3][columnIndex])) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 3 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 3 && target.equals("X")) {
                        isXWin = true;
                    }
                } else {
                    int count = 1;
                    for (int columnIndex = 1; columnIndex < 4; columnIndex++) {
                        if (target.equals(board[3][columnIndex]) || board[3][columnIndex].equals("T")) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 4 && target.equals("O")) {
                        isOWin = true;
                    } else if (count == 4 && target.equals("X")) {
                        isXWin = true;
                    }
                }

                String answer = "";
                if (isOWin && !isXWin) {
                    answer = "O won";
                } else if (!isOWin && isXWin) {
                    answer = "X won";
                } else if (isOWin && isXWin) {
                    answer = "Draw";
                } else if (!isOWin && !isXWin && !isEmptyBoard) {
                    answer = "Draw";
                } else if (!isOWin && !isXWin && isEmptyBoard) {
                    answer = "Game has not completed";
                }

                System.out.println("#" + test_case + " " + answer);
            }
        }
    }
}
