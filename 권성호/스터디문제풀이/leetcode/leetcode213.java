package leetcode;

public class leetcode213 {
    public int rob(int[] nums) {

        if(nums.length == 1)
            return nums[0];
        else if(nums.length == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        else if(nums.length == 3){
            int tmax;
            tmax = nums[0] > nums[1] ? nums[0] : nums[1];
            return tmax > nums[2] ? tmax : nums[2];
        }

        //무조건 0번째 원소를 빼는 경우
        int[] DP1 = new int[100];
        DP1[1] = nums[1];
        DP1[2] = nums[1] > nums[2] ? nums[1] : nums[2];
        for(int i = 3;i<nums.length;i++){
            DP1[i] = DP1[i-1] > DP1[i-2] + nums[i] ? DP1[i-1] : DP1[i-2] + nums[i];
        }

        //무조건 0번째 원소를 포함하는 경우
        int[] DP2 = new int[100];
        DP2[2] = nums[2];
        DP2[3] = nums[2] > nums[3] ? nums[2] : nums[3];
        for(int i = 4;i<nums.length - 1;i++){
            DP2[i] = DP2[i-1] > DP2[i-2] + nums[i] ? DP2[i-1] : DP2[i-2] + nums[i];
        }


        return DP1[nums.length-1] > DP2[nums.length-2] + nums[0]? DP1[nums.length-1] : DP2[nums.length-2] + nums[0];
    }
}
