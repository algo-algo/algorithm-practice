package leetcode;

public class Leetcode299 {
    public String getHint(String secret, String guess) {
        int bullcnt = 0,cowCnt = 0;
        int[] digitCnt = new int[10];
        boolean[] visited = new boolean[secret.length()];
        for(int i = 0 ; i < secret.length();i++){
            if(secret.charAt(i) != guess.charAt(i))
                continue;
            bullcnt++;
            visited[i] = true;
        }
        for(int i = 0 ; i < secret.length();i++){
            if(visited[i])
                continue;
            digitCnt[secret.charAt(i)-'0']++;
        }

        for(int i = 0 ; i < secret.length();i++){
            if(visited[i] || digitCnt[guess.charAt(i)-'0'] <= 0)
                continue;
            digitCnt[guess.charAt(i)-'0']--;
            cowCnt++;
        }
        return Integer.toString(bullcnt) + "A" +  Integer.toString(cowCnt) + "B";
    }
}
