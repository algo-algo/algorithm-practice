package kakao;

import java.util.*;

public class WinterIntern2019SteppingStone {
    public static void main(String[] args) {
        int[] stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
        int k = 3;
        int result = 3;

        Solution solution = new Solution();
        int answer = solution.solution(stones, k);
        System.out.println("answer: " + answer);
        System.out.println("result: " + result);
    }

    static class Solution {
        private final Queue<Integer> slidingWindow = new LinkedList<>();

        public int solution(int[] stones, int k) {
            int stonesLength = stones.length;

            for (int i = 0; i < k; i++) {
                slidingWindow.add(stones[i]);
            }

            int maxStone = getMaxStoneInSlidingWindow();
            int nowMaxStone = maxStone;

            for (int i = k; i < stonesLength; i++) {
                int stone = stones[i];
                int pollStone = slidingWindow.poll();
                slidingWindow.add(stone);

                if (nowMaxStone == pollStone) {
                    if (stone != pollStone) {
                        int maxStoneInSlidingWindow = getMaxStoneInSlidingWindow();
                        nowMaxStone = maxStoneInSlidingWindow;
                        if (maxStoneInSlidingWindow < maxStone) {
                            maxStone = maxStoneInSlidingWindow;
                        }
                    }
                } else {
                    if (nowMaxStone < stone) {
                        nowMaxStone = stone;
                    }
                }
            }

            return maxStone;
        }

        private int getMaxStoneInSlidingWindow() {
           return slidingWindow.stream()
                   .max(Integer::compare)
                   .get();
        }
    }
}
