package boj;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Boj3197 {
    private static final String ICE = "X";
    private static final String WATER = ".";
    private static final String SWAN = "L";
    private static final int[] DX = {-1, 1, 0, 0};
    private static final int[] DY = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = br.readLine();
        String[] numbers = line.split(" ");
        int R = Integer.parseInt(numbers[0]);
        int C = Integer.parseInt(numbers[1]);

        Lake[][] lakes = new Lake[R][C];
        boolean[][] visited = new boolean[R][C];
        Queue<Pair> swanMoves = new LinkedList<>();
        Queue<Pair> waters = new LinkedList<>();
        List<Pair> swanPairs = new ArrayList<>();
        for (int i = 0; i < R; i++) {
            line = br.readLine();
            String[] types = line.split("");
            for (int j = 0; j < C; j++) {
                Pair pair = new Pair(i, j);
                lakes[i][j] = new Lake(types[j]);
                if (types[j].equals(SWAN)) {
                    swanPairs.add(pair);
                    waters.add(pair);
                    if (swanMoves.size() == 0) {
                        swanMoves.add(pair);
                        visited[i][j] = true;
                    }
                } else if (types[j].equals(WATER)) {
                    waters.add(pair);
                }
            }
        }

        int day = 0;
        boolean[] isMeet = {false};
        while (!isMeet[0]) {
            swanMoves = swanMove(lakes, swanMoves, visited, R, C, isMeet);
            if (isMeet[0]) {
                break;
            }

            waters = iceMelt(lakes, waters, R, C);
            day++;
        }

        bw.write(String.valueOf(day));

        bw.flush();
        br.close();
        bw.close();
    }

    private static Queue<Pair> swanMove(Lake[][] lakes, Queue<Pair> swanMoves, boolean[][] visited, int R, int C, boolean[] isMeet) {
        Queue<Pair> newSwanMoves = new LinkedList<>();

        while (!swanMoves.isEmpty()) {
            Pair pair = swanMoves.remove();
            int x = pair.getX();
            int y = pair.getY();
            for (int i = 0; i < 4; i++) {
                int dx = x + DX[i];
                int dy = y + DY[i];

                if (dx >= 0 && dx < R && dy >= 0 && dy < C && !visited[dx][dy]) {
                    visited[dx][dy] = true;
                    if (lakes[dx][dy].getType().equals(WATER)) {
                        swanMoves.add(new Pair(dx, dy));
                    } else if (lakes[dx][dy].getType().equals(ICE)) {
                        newSwanMoves.add(new Pair(dx, dy));
                    } else {
                        isMeet[0] = true;
                        return null;
                    }
                }
            }
        }

        return newSwanMoves;
    }

    private static Queue<Pair> iceMelt(Lake[][] lakes, Queue<Pair> waters, int R, int C) {
        Queue<Pair> newWaters = new LinkedList<>();

        while (!waters.isEmpty()) {
            Pair pair = waters.remove();
            int x = pair.getX();
            int y = pair.getY();

            for (int i = 0; i < 4; i++) {
                int dx = x + DX[i];
                int dy = y + DY[i];

                if (dx >= 0 && dx < R && dy >= 0 && dy < C
                        && lakes[dx][dy].getType().equals(ICE)) {
                    lakes[dx][dy].melt();
                    newWaters.add(new Pair(dx, dy));
                }
            }
        }

        return newWaters;
    }

    static class Lake {
        private String type;

        public Lake(String type) {
            this.type = type;
        }

        public String getType() {
            return type;
        }

        public void melt() {
            this.type = WATER;
        }
    }

    static class Pair {
        private final int x;
        private final int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }
}
