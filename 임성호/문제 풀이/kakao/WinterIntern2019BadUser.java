package kakao;

import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

public class WinterIntern2019BadUser {
    public static void main(String[] args) {
//        String[] user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
//        String[] banned_id = {"fr*d*", "abc1**"};
//        int result = 2;

//        String[] user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
//        String[] banned_id = {"*rodo", "*rodo", "******"};
//        int result = 2;

        String[] user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
        String[] banned_id = {"fr*d*", "*rodo", "******", "******"};
        int result = 3;

        Solution solution = new Solution();
        int answer = solution.solution(user_id, banned_id);
        System.out.println("answer: " + answer);
        System.out.println("result: " + result);
    }

    static class Solution {
        private final Set<String> bannedCandidates = new LinkedHashSet<>();
        private final Set<Set<String>> bannedUsers = new HashSet<>();

        public int solution(String[] user_id, String[] banned_id) {
            boolean[] isVisited = new boolean[user_id.length];

            permutation(user_id, banned_id, isVisited, user_id.length, banned_id.length);

            return bannedUsers.size();
        }

        private void permutation(String[] user_id, String[] banned_id, boolean[] isVisited, int n, int r) {
            if (bannedCandidates.size() == r) {
                checkUser(banned_id);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (!isVisited[i]) {
                    isVisited[i] = true;
                    bannedCandidates.add(user_id[i]);
                    permutation(user_id, banned_id, isVisited, n, r);
                    bannedCandidates.remove(user_id[i]);
                    isVisited[i] = false;
                }
            }
        }

        private void checkUser(String[] banned_id) {
            int index = 0;
            for (String bannedCandidate : bannedCandidates) {
                if (!isBanned(bannedCandidate, banned_id[index])) {
                    return;
                }
                index += 1;
            }
            bannedUsers.add(bannedCandidates);
        }

        private boolean isBanned(String userId, String bannedId) {
            if (userId.length() != bannedId.length()) {
                return false;
            } else {
                for (int i = 0; i < bannedId.length(); i++) {
                    char userChar = userId.charAt(i);
                    char bannedChar = bannedId.charAt(i);
                    if (bannedChar != userChar && bannedChar != '*') {
                        return false;
                    }
                }
                return true;
            }
        }
    }
}
