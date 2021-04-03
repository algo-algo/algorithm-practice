package kakao;

import java.util.Arrays;

public class BlindRecruitment2021_3 {
    public static void main(String[] args) {
        String[] info = {"java backend junior pizza 150", "python frontend senior chicken 210",
                "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80",
                "python backend senior chicken 50"};
        String[] query = {"java and backend and junior and pizza 100", "python and frontend and senior and chicken 200",
                "cpp and - and senior and pizza 250", "- and backend and senior and - 150",
                "- and - and - and chicken 100", "- and - and - and - 150"};

        Solution solution = new Solution();
        int[] result = solution.solution(info, query);
        for (int j : result) {
            System.out.print(j + " ");
        }
    }

    static class Solution {
        public int[] solution(String[] info, String[] query) {
            int[] answer = new int[query.length];

            Human[] humans = new Human[info.length];
            for (int i = 0; i < info.length; i++) {
                String information = info[i];
                String language = information.substring(0, information.indexOf(" "));
                information = information.substring(information.indexOf(" ") + 1);
                String jobGroup = information.substring(0, information.indexOf(" "));
                information = information.substring(information.indexOf(" ") + 1);
                String career = information.substring(0, information.indexOf(" "));
                information = information.substring(information.indexOf(" ") + 1);
                String soulFood = information.substring(0, information.indexOf(" "));
                String score = information.substring(information.indexOf(" ") + 1);
                humans[i] = new Human(language, jobGroup, career, soulFood, score);
            }
            Arrays.sort(humans);

            for (int i = 0; i < query.length; i++) {
                String targetQuery = query[i];
                int targetScore = parseTargetScore(targetQuery);
                int searchIndex = binarySearch(humans, targetScore);
                answer[i] = count(humans, targetQuery, searchIndex);
            }
            System.out.println();

            return answer;
        }

        private int count(Human[] humans, String targetQuery, int searchIndex) {
            int count = 0;
            String language = targetQuery.substring(0, targetQuery.indexOf(" and"));
            targetQuery = targetQuery.substring(targetQuery.indexOf(" and") + 5);
            String jobGroup = targetQuery.substring(0, targetQuery.indexOf(" and"));
            targetQuery = targetQuery.substring(targetQuery.indexOf(" and") + 5);
            String career = targetQuery.substring(0, targetQuery.indexOf(" and"));
            targetQuery = targetQuery.substring(targetQuery.indexOf(" and") + 5);
            String soulFood = targetQuery.substring(0, targetQuery.indexOf(" "));

            for (int i = searchIndex; i < humans.length; i++) {
                Human targetHuman = humans[i];
                if (targetHuman.isFit(language, jobGroup, career, soulFood)) {
                    count++;
                }
            }

            return count;
        }

        private int binarySearch(Human[] humans, int targetScore) {
            int left = 0;
            int right = humans.length - 1;
            int middle = -1;
            int score = 0;

            while (left <= right) {
                middle = (left + right) / 2;
                score = humans[middle].getScore();

                if (score == targetScore) {
                    break;
                }
                if (score <= targetScore) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }

            if (score < targetScore) {
                middle += 1;
            }
            return middle;
        }

        private int parseTargetScore(String targetQuery) {
            StringBuilder reverseScore = new StringBuilder();
            for (int i = targetQuery.length() - 1; i >= 0; i--) {
                char c = targetQuery.charAt(i);
                if (c == ' ') {
                    break;
                }
                reverseScore.append(c);
            }
            reverseScore.reverse();

            return Integer.parseInt(reverseScore.toString());
        }

        static class Human implements Comparable<Human> {
            private final String language;
            private final String jobGroup;
            private final String career;
            private final String soulFood;
            private final int score;

            public Human(String language, String jobGroup, String career, String soulFood, String score) {
                this.language = language;
                this.jobGroup = jobGroup;
                this.career = career;
                this.soulFood = soulFood;
                this.score = Integer.parseInt(score);
            }

            public boolean isFit(String language, String jobGroup, String career, String soulFood) {
                if (!language.equals("-") && !this.language.equals(language)) {
                    return false;
                }
                if (!jobGroup.equals("-") && !this.jobGroup.equals(jobGroup)) {
                    return false;
                }
                if (!career.equals("-") && !this.career.equals(career)) {
                    return false;
                }
                return soulFood.equals("-") || this.soulFood.equals(soulFood);
            }

            public int getScore() {
                return score;
            }

            @Override
            public int compareTo(Human human) {
                if (this.score < human.score) {
                    return -1;
                }
                return 1;
            }
        }
    }
}
