package kakao;

import java.util.*;

public class Intern2020Number3 {
    public static void main(String[] args) {
//        String[] gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
//        int[] result = {3, 7};

        String[] gems = {"DIA", "EM", "EM", "RUB", "DIA"};
        int[] result = {3, 5};

//        String[] gems = {"AA", "AB", "AC", "AA", "AC"};
//        int[] result = {1, 3};

//        String[] gems = {"XYZ", "XYZ", "XYZ"};
//        int[] result = {1, 1};

//        String[] gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
//        int[] result = {1, 5};

        Solution solution = new Solution();
        int[] answer = solution.solution(gems);
        System.out.println(answer[0] + " " + answer[1]);
        System.out.println(Arrays.equals(solution.solution(gems), result));

//        Map<String, String> map = new HashMap<>();
//        map.put("1", "hi1");
//        map.put("2", "hi2");
//        map.put("3", "hi3");
//
//        Map<String, String> copy = new HashMap<>(map);
//        copy.remove("1");
//
//        map.forEach((k, v) -> System.out.println(k + " = " + v));
//        copy.forEach((k, v) -> System.out.println(k + " = " + v));
    }

    // 중복되지 않는 모든 종류의 보석을 포함하는 가장 짧은 길이의 범위를 반환한다.
    // 만약 동일한 길이의 답이 존재한다면 시작 진열대 번호가 가장 짧은 보석의 위치가 답이다.

    static class Solution {
        public int[] solution(String[] gems) {
            int[] answer = new int[2];

            int answerHead = 0;
            int answerTail = 0;

            Set<String> unDuplicatedGems = new HashSet<>(Arrays.asList(gems));
            int unDuplicatedGemsLength = unDuplicatedGems.size();

            int originalGemsLength = gems.length;

            Set<String> slidingWindowSet = new HashSet<>();
            Map<String, Integer> slidingWindowMap = new HashMap<>();

            int headIndex = 0;
            int tailIndex = 0;
            int maximumLength = 100_001;

            for (; headIndex < originalGemsLength; headIndex++) {
                boolean isAllGems = false;

                for (int j = tailIndex; j < originalGemsLength; j++) {
                    String gemName = gems[j];

                    if (!slidingWindowMap.containsKey(gemName)) {
                        slidingWindowMap.put(gemName, 1);
                        slidingWindowSet.add(gemName);
                    } else {
                        int gemValue = slidingWindowMap.get(gemName);
                        slidingWindowMap.replace(gemName, gemValue + 1);
                    }

                    if (slidingWindowSet.size() == unDuplicatedGemsLength) {
                        int allGemsLength = Math.abs(headIndex - j);
                        if (allGemsLength < maximumLength) {
                            answerHead = headIndex;
                            answerTail = j;
                            maximumLength = allGemsLength;
                        }
                        isAllGems = true;
                        tailIndex = j;
                        break;
                    }
                }

                if (!isAllGems) {
                    break;
                }

                removeGem(slidingWindowMap, slidingWindowSet, headIndex, gems);
                removeGem(slidingWindowMap, slidingWindowSet, tailIndex, gems);
            }

            answer[0] = answerHead + 1;
            answer[1] = answerTail + 1;
            return answer;
        }

        private void removeGem(Map<String, Integer> slidingWindowMap,
                               Set<String> slidingWindowSet,
                               int index,
                               String[] gems) {
            String gemName = gems[index];
            if (slidingWindowMap.containsKey(gemName)) {
                int gemValue = slidingWindowMap.get(gemName);
                if (gemValue == 1) {
                    slidingWindowMap.remove(gemName);
                    slidingWindowSet.remove(gemName);
                } else {
                    slidingWindowMap.replace(gemName, gemValue - 1);
                }
            }
        }
    }
}
