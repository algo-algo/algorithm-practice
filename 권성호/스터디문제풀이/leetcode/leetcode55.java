package leetcode;

public class leetcode55 {

    public boolean canJump(int[] nums) {
        if(nums.length == 1)
            return true;

        int currentPose = 0;
        int canGoPose = currentPose + nums[0];

        while(true){
            if(canGoPose >= nums.length - 1)
                return true;

            if(currentPose == canGoPose && nums[currentPose] == 0){
                return false;
            }

            currentPose++;
            if(currentPose >= nums.length - 1)
                return true;
            canGoPose = canGoPose > currentPose + nums[currentPose] ? canGoPose : currentPose + nums[currentPose];
        }

//        return true;
    }
}
