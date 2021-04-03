package sw;

import java.io.FileInputStream;
import java.util.*;

public class Num5644 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/5644_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int M = sc.nextInt(); // 총 이동시간
                int A = sc.nextInt(); // BC의 개수

                // 사용자의 이동 방향 초기화
                int[] aDirections = new int[M + 1];
                int[] bDirections = new int[M + 1];

                for (int i = 1; i <= M; i++) {
                    aDirections[i] = sc.nextInt();
                }
                for (int i = 1; i <= M; i++) {
                    bDirections[i] = sc.nextInt();
                }

                // 보드판 초기화 -> 충전량 등록
                Board[][] boards = new Board[10][10];
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        boards[i][j] = new Board(i, j);
                    }
                }

                for (int i = 0; i < A; i++) {
                    int x = sc.nextInt() - 1;
                    int y = sc.nextInt() - 1;
                    int coverage = sc.nextInt();
                    int performance = sc.nextInt();

                    for (int j = 0; j < 10; j++) {
                        for (int k = 0; k < 10; k++) {
                            if (boards[j][k].isBatteryRange(x, y, coverage)) {
                                boards[j][k].addBatteryChange(i, performance);
                            }
                        }
                    }
                }

                // 이동
                int answer = 0;

                User userA = new User(0, 0);
                User userB = new User(9, 9);

                for (int i = 0; i <= M; i++) {
                    int aDirection = aDirections[i];
                    int bDirection = bDirections[i];

                    // 1. 움직인다.
                    userA.move(aDirection);
                    userB.move(bDirection);

                    // 2. 같은 충전 범위인지 확인한다.
                    Board userABoard = boards[userA.getX()][userA.getY()];
                    Board userBBoard = boards[userB.getX()][userB.getY()];
                    if (userABoard.isSameBatteryCharger(userBBoard)) {
                        // 같은 충전 범위라면
                        // 두 맵의 최댓값을 구해서 답에 더해준다.
                        answer += userABoard.calculateMaxPerformance(userBBoard);
                    } else {
                        // 같은 충전 범위가 아니라면
                        // 첫번째 performance 값을 더한다.
                        answer += userABoard.getMaxPerformance() + userBBoard.getMaxPerformance();
                    }
                }

                System.out.println("#" + test_case + " " + answer);
            }
        }

        static class Board {
            private final int x;
            private final int y;
            private final Map<Integer, Integer> performances = new HashMap<>();

            public Board(int x, int y) {
                this.x = x;
                this.y = y;
                performances.put(-1, 0);
            }

            public boolean isBatteryRange(int x, int y, int coverage) {
                return Math.abs(this.x - x) + Math.abs(this.y - y) <= coverage;
            }

            public void addBatteryChange(int batteryChargerIndex, int performance) {
                performances.put(batteryChargerIndex, performance);
            }

            public boolean isSameBatteryCharger(Board board) {
                Set<Integer> thisKeySet = new HashSet<>(this.performances.keySet());
                Set<Integer> boardKeySet = new HashSet<>(board.performances.keySet());
                thisKeySet.remove(-1);
                boardKeySet.remove(-1);

                for (Integer thisValue : thisKeySet) {
                    for (Integer boardValue : boardKeySet) {
                        if (thisValue.equals(boardValue)) {
                            return true;
                        }
                    }
                }
                return false;
            }

            public int calculateMaxPerformance(Board board) {
                int maxPerformance = -1;
                for (Map.Entry<Integer, Integer> thisEntry : performances.entrySet()) {
                    int thisKey = thisEntry.getKey();
                    int thisValue = thisEntry.getValue();
                    for (Map.Entry<Integer, Integer> boardEntry : board.performances.entrySet()) {
                        int maxCandidate;
                        int boardKey = boardEntry.getKey();
                        int boardValue = boardEntry.getValue();
                        if (thisKey == boardKey) {
                            maxCandidate = boardValue;
                        } else {
                            maxCandidate = boardValue + thisValue;
                        }
                        if (maxPerformance < maxCandidate) {
                            maxPerformance = maxCandidate;
                        }
                    }
                }

                return maxPerformance;
            }

            public int getMaxPerformance() {
                return Collections.max(this.performances.entrySet(),
                        Map.Entry.comparingByValue())
                        .getValue();
            }
        }

        static class User {
            private int x;
            private int y;

            public User(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public void move(int direction) {
                if (direction == 1) {
                    this.y -= 1;
                } else if (direction == 2) {
                    this.x += 1;
                } else if (direction == 3) {
                    this.y += 1;
                } else if (direction == 4) {
                    this.x -= 1;
                }
            }

            public int getX() {
                return x;
            }

            public int getY() {
                return y;
            }
        }
    }
}

