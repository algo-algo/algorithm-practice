package kakao;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Objects;

public class BlindRecruitment2021_5 {
    public static void main(String[] args) {
        String play_time = "02:03:55";
        String adv_time = "00:14:15";
        String[] logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
        String result = "01:30:59";

//        String play_time = "99:59:59";
//        String adv_time = "25:00:00";
//        String[] logs = {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"};
//        String result = "01:00:00";

//        String play_time = "50:00:00";
//        String adv_time = "50:00:00";
//        String[] logs = {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"};
//        String result = "00:00:00";

        Solution solution = new Solution();
        String output = solution.solution(play_time, adv_time, logs);
        System.out.println("my: " + output);
        System.out.println("answer: " + result);
        System.out.println(result.equals(output));
    }

    static class Solution {
        public String solution(String play_time, String adv_time, String[] logs) {
            String answer = "";

            Time playTime = new Time(play_time);
            Time advTime = new Time(adv_time);

            List<Interval> intervals = new ArrayList<>();
            for (String log : logs) {
                String[] timeLogs = log.split("-");
                intervals.add(new Interval(new Time(timeLogs[0]), new Time(timeLogs[1])));
            }
            Collections.sort(intervals);

            if (playTime.equals(advTime)) {
                answer = "00:00:00";
            } else {
                for (Interval interval : intervals) {
                    
                }
            }

            return answer;
        }

        static class Time implements Comparable<Time> {
            private final int hour;
            private final int minute;
            private final int second;

            public Time(String time) {
                String standardTime = time;
                String hour = standardTime.substring(0, standardTime.indexOf(":"));
                standardTime = standardTime.substring(standardTime.indexOf(":") + 1);
                String minute = standardTime.substring(0, standardTime.indexOf(":"));
                standardTime = standardTime.substring(standardTime.indexOf(":") + 1);
                this.hour = Integer.parseInt(hour);
                this.minute = Integer.parseInt(minute);
                this.second = Integer.parseInt(standardTime);
            }

            @Override
            public int compareTo(Time time) {
                if (this.hour < time.hour) {
                    return -1;
                } else if (this.hour > time.hour) {
                    return 1;
                } else if (this.minute < time.minute) {
                    return -1;
                } else if (this.minute > time.minute) {
                    return 1;
                } else if (this.second < time.second) {
                    return -1;
                } else {
                    return 1;
                }
            }

            @Override
            public String toString() {
                String hour = this.hour / 10 >= 1 ? Integer.toString(this.hour) : "0" + this.hour;
                String minute = this.minute / 10 >= 1 ? Integer.toString(this.minute) : "0" + this.minute;
                String second = this.second / 10 >= 1 ? Integer.toString(this.second) : "0" + this.second;
                return hour + ":" + minute + ":" + second;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                Time time = (Time) o;
                return hour == time.hour && minute == time.minute && second == time.second;
            }

            @Override
            public int hashCode() {
                return Objects.hash(hour, minute, second);
            }
        }

        static class Interval implements Comparable<Interval> {
            private final Time startTime;
            private final Time endTime;

            public Interval(Time startTime, Time endTime) {
                this.startTime = startTime;
                this.endTime = endTime;
            }

            @Override
            public int compareTo(Interval interval) {
                if (this.startTime.compareTo(interval.startTime) < 0) {
                    return -1;
                } else if (this.startTime.compareTo(interval.startTime) == 0) {
                    if (this.endTime.compareTo(interval.endTime) < 0) {
                        return -1;
                    }
                }
                return 1;
            }
        }
    }
}
