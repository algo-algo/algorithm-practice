package leetcode;

public class DailyTemperatures739 {
    public static void main(String[] args) {

    }

    static class Solution {
        public int[] dailyTemperatures(int[] T) {
            int[] answers = new int[T.length];

            for (int i = 0; i < T.length; i++) {
                int answer = 1;
                int temperature = T[i];
                for (int j = i + 1; j < T.length; j++) {
                    if (temperature < T[j]) {
                        answers[i] = answer;
                        break;
                    }
                    answer += 1;
                }
            }

            return answers;
        }
    }
}
