package leetcode;


public class leetcode79 {

    private class Pos{
        public int x,y;

        public Pos(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    private boolean ans;
    private boolean[][] visited;
    private int dx[] = {-1,0,1,0};
    private int dy[] = {0,1,0,-1};

    private void initStatus(){
        ans = false;
        visited = new boolean[6][6];
        for(int i = 0 ; i < 6;i++)
            for (int j = 0 ; j < 6;j++)
                visited[i][j] = false;
    }

    private boolean Inboard(Pos p, char[][] board){
        return p.x >=0 && p.x < board.length && p.y >=0 && p.y < board[0].length;
    }

    private void DFS(Pos currentP, char[][] board, String word, String currentWord){
        if(word.equals(currentWord)){
            ans = true;
            return;
        }

        if(currentWord.length() >= word.length())
            return;

        for(int i = 0;i<4;i++){
            Pos nextP = new Pos(currentP.x + dx[i],currentP.y + dy[i]);
            if(Inboard(nextP,board) && !visited[nextP.x][nextP.y]){
                visited[nextP.x][nextP.y] = true;
                DFS(nextP, board, word, currentWord + board[nextP.x][nextP.y]);
                if(ans)
                    return;
                visited[nextP.x][nextP.y] = false;
            }
        }
    }

    public boolean exist(char[][] board, String word) {
        initStatus();
        for(int r = 0; r<board.length;r++){
            for(int c = 0 ; c < board[0].length;c++){
                if(board[r][c] != word.charAt(0))
                    continue;
                visited[r][c] = true;
                DFS(new Pos(r,c), board, word, String.valueOf(board[r][c]));
                if(ans)
                    return true;
                visited[r][c] = false;
            }
        }
        return ans;
    }
}
