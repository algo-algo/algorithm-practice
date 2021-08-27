package leetcode;

import java.util.Arrays;

public class leetcode881 {

    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int front = 0, end = people.length - 1;
        int ans = 0;
        while(front < end){
            if(people[front] + people[end] <= limit)
                front++;
            end--;ans++;
        }
        if(front == end)
            ans++;
        return ans;
    }

}
