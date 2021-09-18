package leetcode;

import java.util.ArrayList;
import java.util.List;

public class leetcode39 {

    private List<List<Integer>> ans;

    private void initStatus(){
        ans = new ArrayList<>();
    }
    void RepaeatedCombi(int idx, int[] candidates, int target, List<Integer> currentList, int sum){
        if(sum > target)
            return;
        if(sum == target){
            ans.add(new ArrayList<>(currentList));
            return;
        }

        for(int i = idx ; i < candidates.length;i++){
            currentList.add(candidates[i]);
            RepaeatedCombi(i, candidates, target, currentList, sum + candidates[i]);
            currentList.remove(currentList.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        initStatus();
        RepaeatedCombi(0,candidates, target, new ArrayList<>(),0);
        return ans;
    }
}
