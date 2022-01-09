package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class leetcode229 {

    private List<Integer> ans = new ArrayList<>();
    private int factor;

    public List<Integer> majorityElement(int[] nums) {
        Arrays.sort(nums);
        factor = nums.length / 3;
        int cnt = 1;
        int currentVal = nums[0];
        for(int i = 1; i < nums.length; i++){
            if(currentVal == nums[i])
                cnt++;
            else{
                if(cnt > factor)
                    ans.add(currentVal);
                cnt = 1;
                currentVal = nums[i];
            }
        }
        if(cnt > factor)
            ans.add(currentVal);
        return ans;
    }
}
