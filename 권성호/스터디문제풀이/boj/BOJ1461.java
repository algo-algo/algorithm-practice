package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class BOJ1461 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputStr = br.readLine();
        int N = Integer.parseInt(inputStr.split(" ")[0]);
        int M = Integer.parseInt(inputStr.split(" ")[1]);
        inputStr = br.readLine();
        List<Integer> plusList = new ArrayList();
        List<Integer> minusList = new ArrayList();
        for (String ele:inputStr.split(" ")) {
            Integer tmp = Integer.parseInt(ele);
            if(tmp > 0)
                plusList.add(tmp);
            else
                minusList.add(tmp * (-1));
        }

        Collections.sort(plusList,Collections.reverseOrder());
        Collections.sort(minusList,Collections.reverseOrder());
        List<Integer> ansList = new ArrayList<>();
        int cnt = 0;
        for (int ele : plusList) {
            if(cnt == 0)
                ansList.add(ele);
            cnt = (cnt+1) % M;
        }
        cnt = 0;
        for (int ele : minusList) {
            if(cnt == 0)
                ansList.add(ele);
            cnt = (cnt+1) % M;
        }

        Collections.sort(ansList);
        int ans = 0;
        for (int ele:ansList)
            ans += ele * 2;

        ans -= ansList.get(ansList.size()-1);
        System.out.println(ans);
    }
}
