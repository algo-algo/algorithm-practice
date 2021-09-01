package leetcode;

import javafx.util.Pair;

import java.util.ArrayList;
import java.util.List;

public class leetcode885 {

    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int direction = 0;
        int repeatCnt = 1;
        List<Pair<Integer,Integer>> ansList = new ArrayList<>();
        ansList.add(new Pair<>(rStart,cStart));

        while (ansList.size() < rows*cols){
            for(int k=0;k<2;k++){
                for(int i = 0 ; i < repeatCnt;i++){
                    if(direction == 0)
                        cStart++;
                    else if(direction == 1)
                        rStart++;
                    else if(direction == 2)
                        cStart--;
                    else
                        rStart--;

                    if(rStart >=0 && rStart < rows && cStart >=0 && cStart <cols){
                        ansList.add(new Pair<>(rStart,cStart));
                    }
                }
                direction = (direction + 1) %4;
            }
            repeatCnt++;
        }

        int ans[][] = new int[ansList.size()][2];
        for(int i = 0 ; i < ansList.size();i++){
            ans[i][0] = ansList.get(i).getKey();
            ans[i][1] = ansList.get(i).getValue();

        }
        return ans;
    }
}
