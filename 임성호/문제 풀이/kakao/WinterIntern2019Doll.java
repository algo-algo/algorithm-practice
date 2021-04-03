package kakao;

import java.util.Stack;

public class WinterIntern2019Doll {
    public static void main(String[] args) {
        int[][] board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
        int[] moves = {1, 5, 3, 5, 1, 2, 1, 4};
        int answer = 4;

        Solution solution = new Solution();
        System.out.println(solution.solution(board, moves));
    }

    static class Solution {
        public int solution(int[][] board, int[] moves) {
            int answer = 0;

            Stack<Integer> dolls = new Stack<>();

            for (int move : moves) {
                int craneIndex = move - 1;
                for (int i = 0; i < board.length; i++) {
                    if (board[i][craneIndex] != 0) {
                        int doll = board[i][craneIndex];
                        board[i][craneIndex] = 0;
                        if (!dolls.isEmpty() && dolls.peek().equals(doll)) {
                            answer += 2;
                            dolls.pop();
                        } else {
                            dolls.push(doll);
                        }
                        break;
                    }
                }
            }

            return answer;
        }
    }
}
