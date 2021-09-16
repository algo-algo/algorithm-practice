package leetcode;

public class leetcode209 {

    private long[] sum;
    private int ans;

    public int minSubArrayLen(int target, int[] nums) {
        ans = Integer.MAX_VALUE;
        sum = new long[nums.length + 1];
        sum[0] = 0;
        sum[1] = nums[0];
        for(int i = 2;i<=nums.length;i++)
            sum[i] = sum[i-1] + nums[i - 1];

        int start = 0, end = 1;
        while(start < sum.length && end < sum.length){
            if(sum[end] - sum[start] >= target){
                ans = ans < (end - start) ? ans : (end - start);
                start++;
            }
            else
                end++;
        }


        if(ans == Integer.MAX_VALUE)
            return 0;
        else
            return ans;
    }
}
