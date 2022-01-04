package leetcode;

public class leetcode48 {

    private void show(int[][] matrix){
        for(int i = 0 ; i < matrix.length; i++){
            for(int j = 0 ; j < matrix.length; j++){
                System.out.print(matrix[i][j]);
                System.out.print(" ");
            }
            System.out.print("\n");
        }
    }

    private void change(int[][] matrix, int x, int y){
        int cnt = 0;

        int data = matrix[x][y];
        while(cnt++ < 4){
            int tmp1 = matrix[y][matrix.length - 1 - x];
            matrix[y][matrix.length - 1 - x] = data;

            int tmp2 = y;
            y = matrix.length - 1 - x;
            x = tmp2;
            data = tmp1;
        }
    }

    public void rotate(int[][] matrix) {
        int iterCnt = matrix.length / 2;

        for(int x = 0; x < iterCnt; x++){
            for(int y = x; y < matrix.length - x - 1; y++){
                change(matrix, x,y);
            }
        }

        show(matrix);
    }
}
