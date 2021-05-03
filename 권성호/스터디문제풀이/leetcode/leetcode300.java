package leetcode;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class leetcode300 {
    public int lengthOfLIS(int[] nums) {
        List<Integer> list = new ArrayList<>();
        list.add(nums[0]);
        for(int i = 1 ; i < nums.length;i++){
            int idx = Collections.binarySearch(list,nums[i]);
            if(idx >= 0)
                continue;
            int realIdx = -1 - idx;
            if(realIdx == list.size())
                list.add(nums[i]);
            else
                list.set(realIdx, nums[i]);
        }


        return list.size();
    }
}