package leetcode;

public class leetcode64 {
    public int minPathSum(int[][] grid) {
        int rowLen = grid.length;
        int colLen = grid[0].length;

        for(int c = 1 ; c < colLen ; c++)
            grid[0][c] = grid[0][c] + grid[0][c-1];

        for(int r = 1 ; r < rowLen ; r++)
            grid[r][0] = grid[r][0] + grid[r - 1][0];

        for(int r = 1;r<rowLen;r++){
            for(int c = 1; c < colLen;c++){
                grid[r][c] = grid[r][c] + (grid[r][c-1] < grid[r-1][c]?grid[r][c-1] : grid[r-1][c]);
            }
        }

        return grid[rowLen - 1][colLen - 1];
    }
}
