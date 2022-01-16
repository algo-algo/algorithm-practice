package leetcode;

public class leetcode59 {

    private int oneCycle(int[][] ans, int val, int r, int c){
        //오른쪽
        while(c < ans.length && ans[r][c] == 0){
            ans[r][c++] = val++;
        }
        c--;
        r++;

        //아래
        while(r < ans.length && ans[r][c] == 0){
            ans[r++][c] = val++;
        }
        r--;
        c--;

        //왼쪽
        while(c >= 0 && ans[r][c] == 0){
            ans[r][c--] = val++;
        }
        c++;
        r--;

        //위
        while(r >= 0 && ans[r][c] == 0){
            ans[r--][c] = val++;
        }
        return val;
    }

    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int len = ans.length/2 + ans.length % 2;
        int val = 1;
        for(int i = 0;i < len;i++ )
            val = oneCycle(ans, val, i, i);
        return ans;
    }
}
