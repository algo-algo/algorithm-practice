package sw;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        int[][] arr1 = new int[2][2];
        int[][] arr2 = new int[2][2];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                arr1[i][j] = 1;
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                arr2[i][j] = arr1[i][j];
            }
        }

        arr1[1][1] = 4;
        System.out.println(arr2[1][1]);
    }
}
