package sw;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Num2112 {
    private static int D;
    private static int W;
    private static int K;
    private static int injection;
    private static int minimumInjection;

    public static void main(String args[]) throws Exception {
        System.setIn(new FileInputStream("src/sw/res/2112_input.txt"));

        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            D = sc.nextInt();
            W = sc.nextInt();
            K = sc.nextInt();
            injection = 0;

            int[][] cells = new int[D][W];
            for (int i = 0; i < D; i++) {
                for (int j = 0; j < W; j++) {
                    cells[i][j] = sc.nextInt();
                }
            }

            List<Integer> nonAcceptanceFilms = getNonAcceptanceFilms(cells);

            minimumInjection = 14;

            for (int nonAcceptanceFilmsIndex : nonAcceptanceFilms) {
                int[][] injectionCells = makeInjectionCells(cells);
                List<Integer> injectionRow = new ArrayList<>();
                
            }

            injection = injection == 0 ? 0 : minimumInjection;
        }
    }

    private static int[][] makeInjectionCells(int[][] cells) {
        int[][] injectionCells = new int[D][W];
        for (int i = 0; i < D; i++) {
            if (W >= 0) System.arraycopy(cells[i], 0, injectionCells[i], 0, W);
        }
        return injectionCells;
    }

    private static List<Integer> getNonAcceptanceFilms(int[][] cells) {
        List<Integer> nonAcceptanceFilms = new ArrayList<>();

        for (int i = 0; i < W; i++) {
            boolean isAcceptance = false;
            for (int j = 0; j <= D - K; j++) {
                int candidate = cells[j][i];
                for (int k = 1; k < K; k++) {
                    int compare = cells[j + k][i];
                    if (candidate != compare) {
                        isAcceptance = false;
                        break;
                    }
                    isAcceptance = true;
                }
                if (isAcceptance) {
                    break;
                }
            }
            if (!isAcceptance) {
                nonAcceptanceFilms.add(i);
            }
        }

        return nonAcceptanceFilms;
    }

    private static void dfs(int index, int[][] cells) {
        if (index == W) {
            if (injection < minimumInjection) {
                minimumInjection = injection;
            }
            return;
        }
    }
}
