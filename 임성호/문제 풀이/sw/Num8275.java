package sw;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Num8275 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/8275_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int N = sc.nextInt();
                int X = sc.nextInt();
                int M = sc.nextInt();

                Cage[] cages = new Cage[N];
                for (int i = 0; i < N; i++) {
                    cages[i] = new Cage();
                }

                List<TestCase> testCases = new ArrayList<>();
                for (int i = 0; i < M; i++) {
                    int l = sc.nextInt() - 1;
                    int r = sc.nextInt() - 1;
                    int s = sc.nextInt();
                    testCases.add(new TestCase(l, r, s));
                }

                int testCaseIndex = 0;
                int[] answer = new int[N];
                int[] maxSum = {0};

                dfs(cages, testCases, testCaseIndex, answer, maxSum, X);
            }
        }

        private static void dfs(Cage[] cages, List<TestCase> testCases, int testCaseIndex, int[] answer, int[] maxSum, int maxHamsterCount) {
            if (testCaseIndex == testCases.size()) {
                int cagesSum = getCagesSum(cages);
                if (maxSum[0] < cagesSum) {
                    maxSum[0] = cagesSum;
                    setAnswer(cages, answer, maxHamsterCount);
                }
                return;
            }

            TestCase testCase = testCases.get(testCaseIndex);
            List<Integer> indexes = new ArrayList<>();
            int sum = testCase.sum;
            for (int i = testCase.end; i >= testCase.start; i--) {
                if (!cages[i].isChanged) {
                    indexes.add(i);
                } else {
                    sum -= cages[i].hamsterCount;
                }
            }

            boolean isLastGreedy = false;
            while (!isLastGreedy) {
                isLastGreedy = greedy(cages, indexes, sum, maxHamsterCount);
                if (!isLastGreedy) {
                    dfs(cages, testCases, testCaseIndex + 1, answer, maxSum, maxHamsterCount);
                }
            }
        }

        private static boolean greedy(Cage[] cages, List<Integer> indexes, int sum, int maxHamsterCount) {
            for (int index : indexes) {

            }
            return false;
        }

        private static int getCagesSum(Cage[] cages) {
            int sum = 0;
            for (int i = 0; i < cages.length; i++) {
                sum += cages[i].hamsterCount;
            }
            return sum;
        }

        private static void setAnswer(Cage[] cages, int[] answer, int maxHamsterCount) {
            for (int i = 0; i < cages.length; i++) {
                if (!cages[i].isChanged) {
                    answer[i] = maxHamsterCount;
                } else {
                    answer[i] = cages[i].hamsterCount;
                }
            }
        }

        static class Cage {
            private int hamsterCount = 0;
            private boolean isChanged = false;

            public void changeCount(int hamsterCount) {
                this.hamsterCount = hamsterCount;
                isChanged = true;
            }
        }

        static class TestCase {
            private final int start;
            private final int end;
            private final int sum;

            public TestCase(int start, int end, int sum) {
                this.start = start;
                this.end = end;
                this.sum = sum;
            }
        }
    }
}
