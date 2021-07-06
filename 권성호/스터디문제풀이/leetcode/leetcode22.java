package leetcode;

import java.util.ArrayList;
import java.util.List;

public class leetcode22 {

    private List<String> ans = new ArrayList<>();

    private void BackTracking(int n, int c1, int c2, String currentStr){
        if(c1 == n){
            for(int i = 0 ; i < n-c2;i++)
                currentStr = currentStr + ")";
            ans.add(new String(currentStr));
            return;
        }

        if(c2 == n){
            ans.add(new String(currentStr));
            return;
        }
        if(c1 > c2)
            BackTracking(n,c1,c2 + 1,currentStr + ")");
        BackTracking(n,c1+1,c2,currentStr + "(");
    }


    public List<String> generateParenthesis(int n) {
        BackTracking(n,0,0,"");
        return ans;
    }
}
