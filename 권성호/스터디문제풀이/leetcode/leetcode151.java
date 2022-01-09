package leetcode;


public class leetcode151 {

    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        int start = -1, end = -1;
        for(int i = s.length()-1;i>=0;i--){
            if(s.charAt(i) == ' '){
                if(end != -1){
                    sb.append(s,start, end + 1);
                    sb.append(' ');
                    start = -1;
                    end = -1;
                }
                continue;
            }

            if(end == -1){
                start = i;
                end = i;
                continue;
            }

            start--;
        }

        if(end != -1)
            sb.append(s,start, end + 1);

        if(sb.charAt(sb.length() - 1) == ' ')
            sb.deleteCharAt(sb.length() - 1);

        return sb.toString();
    }
}
