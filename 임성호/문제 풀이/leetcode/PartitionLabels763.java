package leetcode;

import java.util.*;

public class PartitionLabels763 {
    public static void main(String[] args) {
        String S = "fififfififiyyiiyiiyfiyiiyyyyiiiccccccccccccccccccccccccccrrrrrrrrrrrrrrrrrrrrrrrrrrrvqvqvqqvqqqvqqvqqqqqvqqqqvqqvqvggggggggggggggggggggggggggggggggllllllllllllllllllllllllllllllllllllllnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnusuutttsutuuttuttstsutustsussssstuuttstkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkooddodoododoodoodddddodooddodoodomeeeeemmeeemmmmemmmemmeemmemeeemmmemzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzpphjhjjjpjhhjjhphpjhhpjhhjjjhjjjpphjpphhjjjxxxxxxxxxxxxxxxxxxxxxxxxxawbwbbwwabbawwwwbawaabawaawaawbbwbawbb";
        Solution solution = new Solution();
        List<Integer> answers = solution.partitionLabels(S);
        System.out.print("[");
        answers.forEach(i -> {
            System.out.print(i + ", ");
        });
        System.out.print("]");
    }

    static class Solution {
        public List<Integer> partitionLabels(String S) {
            String[] alphabets = S.split("");
            Set<String> unDuplicatedAlphabets = new LinkedHashSet<>(Arrays.asList(alphabets));
            List<String> unDuplicatedAlphabetsList = new ArrayList<>(unDuplicatedAlphabets);

            List<Integer> answers = new ArrayList<>();
            List<Integer> tempAnswers = new ArrayList<>();

            recursiveSplitString(answers, tempAnswers, unDuplicatedAlphabetsList, 0, S);

            return answers;
        }

        private void recursiveSplitString(List<Integer> answers, List<Integer> tempAnswers,
                                          List<String> unDuplicatedAlphabetsList, int index, String s) {
            if (s.length() == 0 && tempAnswers.size() > answers.size()) {
                answers.clear();
                answers.addAll(tempAnswers);
                return;
            }

            for (int i = index; i < unDuplicatedAlphabetsList.size(); i++) {
                String alphabet = unDuplicatedAlphabetsList.get(i);
                if (s.contains(alphabet)) {
                    int lastIndexOfAlphabet = s.lastIndexOf(alphabet);
                    String cut = s.substring(0, lastIndexOfAlphabet + 1);
                    String[] cutAlphabets = cut.split("");
                    Set<String> unDuplicatedCutAlphabets = new HashSet<>(Arrays.asList(cutAlphabets));
                    String remain = s.substring(lastIndexOfAlphabet + 1);
                    if (!isContain(unDuplicatedCutAlphabets, remain)) {
                        tempAnswers.add(cut.length());

                        recursiveSplitString(answers, tempAnswers, unDuplicatedAlphabetsList, i + 1, remain);
                        return;
                    }
                }
            }
        }

        private boolean isContain(Set<String> unDuplicatedCutAlphabets, String remain) {
            boolean isContain = false;
            for (String alphabet : unDuplicatedCutAlphabets) {
                if (remain.contains(alphabet)) {
                    isContain = true;
                    break;
                }
            }
            return isContain;
        }
    }
}
