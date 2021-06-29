class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0)
            return false;
        String xStr = Integer.toString(x);
        for(int i = 0 ; i < xStr.length()/2;i++){
            if(xStr.charAt(i) == xStr.charAt(xStr.length()-1-i))
                continue;
            else
                return false;
        }
        return true;
    }
}
