package kakao;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedHashSet;
import java.util.Set;

public class WinterIntern2019Tuple {
    public static void main(String[] args) {
//        String s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
//        int[] answer = {2, 1, 3, 4};

//        String s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
//        int[] answer = {2, 1, 3, 4};

        String s = "{{20,111},{111}}";
        int[] answer = {111, 20};

//        String s = "{{123}}";
//        int[] answer = {123};

//        String s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
//        int[] answer = {3, 2, 4, 1};

        Solution solution = new Solution();
        int[] myAnswer = solution.solution(s);
        System.out.print("myAnswer: ");
        for (int j : myAnswer) {
            System.out.print(j + " ");
        }
        System.out.println();

        System.out.print("answer: ");
        for (int j : answer) {
            System.out.print(j + " ");
        }
        System.out.println();
    }

    static class Solution {
        public int[] solution(String s) {
            String tuplesCandidates = s.substring(0, s.length() - 1);
            tuplesCandidates = tuplesCandidates.substring(1) + ",";
            tuplesCandidates = tuplesCandidates.replaceAll("\\{", "");

            String[] tuples = tuplesCandidates.split("},");

            tuples = Arrays.stream(tuples)
                    .sorted(Comparator.comparing(String::length))
                    .toArray(String[]::new);

            Set<Integer> answers = new LinkedHashSet<>();
            for (String numbers : tuples) {
                String[] candidates = numbers.split(",");
                for (String number : candidates) {
                    answers.add(Integer.parseInt(number));
                }
            }
            
            return answers.stream()
                    .mapToInt(i -> i)
                    .toArray();
        }
    }
}
