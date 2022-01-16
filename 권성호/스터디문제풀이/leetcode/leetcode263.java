package leetcode;

public class leetcode263 {
    private static int[] dividedFactors = new int[]{2,3,5};

    private int divideByFactor(int target, int factor){
        while (target % factor == 0){
            target /= factor;
        }
        return target;
    }

    private int divideByFactors(int target){
        for(int factor: dividedFactors){
            target = divideByFactor(target, factor);
        }
        return target;
    }

    public boolean isUgly(int target) {
        if(target == 0)
            return true;
        return (divideByFactors(target) == 1);
    }
}
