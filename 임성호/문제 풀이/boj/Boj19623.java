package boj;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Boj19623 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        List<Conference> conferences = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            String[] lines = line.split(" ");
            conferences.add(new Conference(Integer.parseInt(lines[0]), Integer.parseInt(lines[1]), Integer.parseInt(lines[2])));
        }
        Collections.sort(conferences);

        int max = 0;
        for (int i = 0; i < N; i++) {
            Conference conference = conferences.get(i);
            int maxPeople = 0;
            boolean isChange = false;
            for (int j = i - 1; j >= 0; j--) {
                Conference compare = conferences.get(j);
                if (compare.endTime < conference.startTime) {
                    maxPeople = Math.max(maxPeople, conference.people + compare.people);
                    isChange = true;
                }
            }
            if (isChange) {
                conference.setPeople(maxPeople);
            }
            max = Math.max(max, conference.people);
        }
        bw.write(String.valueOf(max));

        bw.flush();
        br.close();
        bw.close();
    }

    static class Conference implements Comparable<Conference> {
        private final int startTime;
        private final int endTime;
        private int people;

        public Conference(int startTime, int endTime, int people) {
            this.startTime = startTime;
            this.endTime = endTime;
            this.people = people;
        }

        @Override
        public int compareTo(Conference conference) {
            if (this.startTime < conference.startTime) {
                return -1;
            }
            return 1;
        }

        public void setPeople(int people) {
            this.people = people;
        }
    }
}
