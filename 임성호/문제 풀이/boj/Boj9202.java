package boj;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Boj9202 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int w = Integer.parseInt(br.readLine());
        List<String> words = new ArrayList<>();
        for (int i = 0; i < w; i++) {
            words.add(br.readLine());
        }
        br.readLine();

        Trie trie = new Trie();
        words.forEach(trie::insert);

        int b = Integer.parseInt(br.readLine());
        for (int i = 0; i < b; i++) {
            char[][] board = new char[4][4];
            for (int j = 0; j < 4; j++) {
                String line = br.readLine();
                for (int k = 0; k < 4; k++) {
                    board[j][k] = line.charAt(k);
                }
            }

            if (i + 1 < b) {
                br.readLine();
            }

            dfsRecursive(trie, board, bw);
        }

        bw.flush();
        br.close();
        bw.close();
    }

    private static void dfsRecursive(Trie trie, char[][] board, BufferedWriter bw) throws IOException {
        boolean[][] visited = new boolean[4][4];
        int[] totalWordCount = {0};
        int[] totalScore = {0};
        String[] maxLengthWord = {""};
        Set<String> unDuplicatedWord = new HashSet<>();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                StringBuilder stringBuilder = new StringBuilder();
                TrieNode rootNode = trie.root;
                dfs(rootNode, board, i, j, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }
        }

        bw.write(String.valueOf(totalScore[0]) + " " + maxLengthWord[0] + " " + String.valueOf(totalWordCount[0]) + "\n");
    }

    private static void dfs(TrieNode trieNode, char[][] board, int i, int j, boolean[][] visited, int[] totalWordCount, int[] totalScore, StringBuilder stringBuilder, String[] maxLengthWord, Set<String> unDuplicatedWord) {
        char c = board[i][j];
        visited[i][j] = true;
        if (trieNode.children.containsKey(c)) {
            stringBuilder.append(c);

            TrieNode targetNode = trieNode.children.get(c);
            if (targetNode.isEndOfWord && !unDuplicatedWord.contains(stringBuilder.toString())) {
                unDuplicatedWord.add(stringBuilder.toString());
                totalWordCount[0] += 1;
                totalScore[0] += Score.calculateScore(stringBuilder);
                compareMaxLengthWord(stringBuilder, maxLengthWord);
            }

            //위
            if (i - 1 >= 0 && !visited[i - 1][j]) {
                dfs(targetNode, board, i - 1, j, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }
            //아래
            if (i + 1 < 4 && !visited[i + 1][j]) {
                dfs(targetNode, board, i + 1, j, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }
            //왼쪽
            if (j - 1 >= 0 && !visited[i][j - 1]) {
                dfs(targetNode, board, i, j - 1, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }
            //오른쪽
            if (j + 1 < 4 && !visited[i][j + 1]) {
                dfs(targetNode, board, i, j + 1, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }
            //오른쪽 위
            if (i - 1 >= 0 && j + 1 < 4 && !visited[i - 1][j + 1]) {
                dfs(targetNode, board, i - 1, j + 1, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }
            //오른쪽 아래
            if (i + 1 < 4 && j + 1 < 4 && !visited[i + 1][j + 1]) {
                dfs(targetNode, board, i + 1, j + 1, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }
            //왼쪽 위
            if (i - 1 >= 0 && j - 1 >= 0 && !visited[i - 1][j - 1]) {
                dfs(targetNode, board, i - 1, j - 1, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }
            //왼쪽 아래
            if (i + 1 < 4 && j - 1 >= 0 && !visited[i + 1][j - 1]) {
                dfs(targetNode, board, i + 1, j - 1, visited, totalWordCount, totalScore, stringBuilder, maxLengthWord, unDuplicatedWord);
            }

            stringBuilder.deleteCharAt(stringBuilder.toString().length() - 1);
        }
        visited[i][j] = false;
    }

    private static void compareMaxLengthWord(StringBuilder stringBuilder, String[] maxLengthWord) {
        String candidate = stringBuilder.toString();
        if (maxLengthWord[0].length() < candidate.length()) {
            maxLengthWord[0] = candidate;
        } else if (maxLengthWord[0].length() == candidate.length()) {
            for (int k = 0; k < maxLengthWord[0].length(); k++) {
                int subtraction = maxLengthWord[0].charAt(k) - candidate.charAt(k);
                if (subtraction < 0) {
                    break;
                } else if (subtraction > 0) {
                    maxLengthWord[0] = candidate;
                    break;
                }
            }
        }
    }

    static class Trie {
        private final TrieNode root = new TrieNode();

        public void insert(String word) {
            TrieNode current = root;

            for (char l : word.toCharArray()) {
                current = current.children.computeIfAbsent(l, c -> new TrieNode());
            }
            current.setEndOfWord(true);
        }
    }

    static class TrieNode {
        private final Map<Character, TrieNode> children = new HashMap<>();
        private boolean isEndOfWord;

        public void setEndOfWord(boolean endOfWord) {
            isEndOfWord = endOfWord;
        }
    }

    enum Score {
        ONE(1, 0),
        TWO(2 , 0),
        THREE(3, 1),
        FOUR(4, 1),
        FIVE(5, 2),
        SIX(6, 3),
        SEVEN(7, 5),
        EIGHT(8, 11);

        private final int length;
        private final int score;

        Score(int length, int score) {
            this.length = length;
            this.score = score;
        }

        private static final Map<Integer, Integer> scores =
                Collections.unmodifiableMap(Stream.of(values())
                .collect(Collectors.toMap(Score::getLength, Score::getScore)));

        public static int calculateScore(StringBuilder stringBuilder) {
            String word = stringBuilder.toString();
            return scores.get(word.length());
        }

        public int getLength() {
            return length;
        }

        public int getScore() {
            return score;
        }
    }
}
