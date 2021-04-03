package boj;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Boj1691 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String boardLength = bf.readLine();
        String[] boardLengths = boardLength.split(" ");
        int W = Integer.parseInt(boardLengths[0]);
        int H = Integer.parseInt(boardLengths[1]);

        List<Board> boards = new ArrayList<>();
        int N = Integer.parseInt(bf.readLine());
        for (int i = 0; i < N; i++) {
            boardLength = bf.readLine();
            boardLengths = boardLength.split(" ");
            int boardWidth = Integer.parseInt(boardLengths[0]);
            int boardHeight = Integer.parseInt(boardLengths[1]);
            boards.add(new Board(boardWidth, boardHeight));
        }

        boards.sort(Collections.reverseOrder());
        int minimumSize = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            Board board = new Board(W, H);
            int minimum = 0;
            for (int j = i; j < N; j++) {
                Board targetBoard = boards.get(j);
                minimum += calculateRemainder(board, targetBoard);
            }
            if (board.getWidth() != 0 && board.getHeight() != 0) {
                minimum += board.getWidth() * board.getHeight();
            }
            if (minimum < minimumSize) {
                minimumSize = minimum;
            }
        }

        bw.write(String.valueOf(minimumSize));

        bw.flush();
        bf.close();
        bw.close();
    }

    private static int calculateRemainder(Board board, Board targetBoard) {
        int boardWidth = board.getWidth();
        int boardHeight = board.getHeight();
        int targetBoardWidth = targetBoard.getWidth();
        int targetBoardHeight = targetBoard.getHeight();
        if (!(targetBoardWidth <= boardWidth && targetBoardHeight <= boardHeight)) {
            board.cutSize(0, 0);
            return boardWidth * boardHeight;
        }
        int width = boardWidth % targetBoardWidth;
        board.cutSize(boardWidth, boardHeight - targetBoardHeight);
        return width * targetBoardHeight;
    }

    static class Board implements Comparable<Board> {
        private int width;
        private int height;

        public Board(int width, int height) {
            this.width = width;
            this.height = height;
        }

        public void cutSize(int width, int height) {
            this.width = width;
            this.height = height;
        }

        public int getWidth() {
            return width;
        }

        public int getHeight() {
            return height;
        }

        @Override
        public int compareTo(Board board) {
            if (this.width < board.width) {
                return -1;
            } else if (this.width == board.width && this.height < board.height) {
                return -1;
            }
            return 1;
        }
    }
}
