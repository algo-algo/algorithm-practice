package sw;

import java.io.FileInputStream;
import java.util.*;

public class Num4111 {
    static class Solution {
        public static void main(String args[]) throws Exception {

            System.setIn(new FileInputStream("src/sw/res/4111_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int testCase = 1; testCase <= T; testCase++) {
                int N = sc.nextInt();
                int K = sc.nextInt();
                Set<Integer> cameras = new HashSet<>();
                for (int i = 0; i < N; i++) {
                    cameras.add(sc.nextInt());
                }

                List<Integer> nonDuplicatedCameras = new ArrayList<>(cameras);
                Collections.sort(nonDuplicatedCameras);

                List<Integer> distances = new ArrayList<>();
                for (int i = 1; i < nonDuplicatedCameras.size(); i++) {
                    distances.add(nonDuplicatedCameras.get(i) - nonDuplicatedCameras.get(i - 1));
                }
                Collections.sort(distances);
                
                int answer = 0;
                for (int i = 0; i < distances.size() - (K - 1); i++) {
                    answer += distances.get(i);
                }
                System.out.println("#" + testCase + " " + answer);
            }
        }
    }
}
