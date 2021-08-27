package leetcode;

public class leetcode357 {

    private int ans = 0;
    private boolean check[] = new boolean[10];

    void DFS(int n, int depth){
        if(depth == n)
            return;
        if(depth == 0){
            for(int i = 1; i < check.length;i++){
                if(!check[i]){
                    ans++;
                    check[i] = true;
                    DFS(n,depth+1);
                    check[i] = false;
                }
            }
        }
        else {
            for(int i = 0; i < check.length;i++){
                if(!check[i]){
                    ans++;
                    check[i] = true;
                    DFS(n,depth+1);
                    check[i] = false;
                }
            }
        }
    }

    public int countNumbersWithUniqueDigits(int n) {
        ans = 0;
        for(int i = 0 ; i < check.length;i++)
            check[i] = false;
        DFS(n,0);
        return ans + 1;
    }

}
