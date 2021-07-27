package leetcode;

public class Leetcode1947 {
    private int[][] student;
    private int[][] mentors;
    private boolean isUsed[] = new boolean[8];
    private int permutation[] = new int[8];
    private int ans = 0;
    private int humCnt;
    private int questionCnt;

    private void UpdateANS(){
        int cnt = 0;
        for(int i = 0 ; i < humCnt;i++){
            for(int j = 0 ; j < questionCnt;j++){
                if((student[i][j] == mentors[permutation[i]][j]))
                    cnt++;
            }
        }
        ans = ans > cnt? ans : cnt;
    }

    private void Permutation(int depth){
        if(depth == humCnt){
            UpdateANS();
            return;
        }

        for(int i = 0 ; i < humCnt;i++){
            if(isUsed[i] == true)
                continue;

            permutation[depth] = i;
            isUsed[i] = true;
            Permutation(depth+1);
            isUsed[i] = false;
        }
    }

    public int maxCompatibilitySum(int[][] s, int[][] m) {
        student = s;
        mentors = m;
        humCnt = s.length;
        questionCnt = s[0].length;
        for(int i = 0 ; i < humCnt;i++)
            isUsed[i] = false;
        Permutation(0);
        return ans;
    }
}
