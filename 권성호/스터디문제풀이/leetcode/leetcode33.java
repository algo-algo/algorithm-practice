public class leetcode33 {

    private int findMinIdx(int[] nums){
        if(nums.length == 0)
            return -1;
        if(nums.length == 1)
            return 0;

        int start = 0, end = nums.length-1;
        int mid = -1;
        while(start <= end){
            mid = (start + end)/2;
            if(nums[mid] > nums[end])
                start = mid;
            else
                end = mid;

            if(start == end)
                return start;

            if(start + 1 == end){
                return nums[start] < nums[end] ? start : end;
            }
        }
        return mid;
    }

    int serachTargetIdx(int nums[], int minIdx, int target){
        int start = 0, end = nums.length-1;
        int mid;
        while(start <=end){
            mid = (start + end)/2;
            int convertedIdx = (mid + minIdx) % nums.length;
            if(nums[convertedIdx] == target)
                return convertedIdx;
            else if(nums[convertedIdx] > target)
                end = mid -1;
            else
                start = mid + 1;
        }
        return -1;
    }

    public int search(int[] nums, int target) {
        //nums: 오름차순 정렬 되어 있음(원소 중복은 없음)
        int minIdx = findMinIdx(nums);

        return serachTargetIdx(nums,minIdx,target);
    }
}
