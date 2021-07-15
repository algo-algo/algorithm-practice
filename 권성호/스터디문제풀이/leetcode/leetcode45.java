package leetcode;

public class leetcode45 {
    private int DP[] = new int[10000];
    public int jump(int[] nums) {
        for(int i = 0 ; i < nums.length;i++)
            DP[i] = Integer.MAX_VALUE;

        DP[0] = 0;
        for(int i = 0;i<nums.length;i++){
            for(int j = 1; j <= nums[i];j++){
                if(i+j < nums.length && DP[i+j] > DP[i]+1)
                    DP[i+j] = DP[i] + 1;
            }
        }

        return DP[nums.length - 1];
    }
}
