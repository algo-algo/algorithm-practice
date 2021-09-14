package leetcode;

public class leetcode279 {

    private int[] DP = new int[10001];
    private int[] square = new int[100];

    private void initStatus(){
        for(int i = 0 ;i<DP.length;i++)
            DP[i] = 0;
        for(int i = 1 ; i <= 100;i++ )
            square[i-1] = i*i;
    }

    public int lowerBound(int value) {
        int low = 0;
        int high = square.length;
        while (low < high) {
            int mid = low + (high - low)/2;
            if (value <= square[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public int numSquares(int n) {
        initStatus();
        DP[1] = 1;
        for(int i = 2;i<=n;i++){
            int idx = lowerBound(i);
            if(square[idx] == i){
                DP[i] = 1;
                continue;
            }
            int min = Integer.MAX_VALUE;
            for(int j = idx - 1;j>=0;j--)
                min = min < DP[i-square[j]] ? min : DP[i-square[j]];

            DP[i] = min + 1;
        }
        return DP[n];
    }
}
