package leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class leetcode436 {

    public class Interval  {
        private int start;
        private int end;
        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int getStart(){
            return start;
        }

        public int getEnd(){
            return end;
        }
    }

    public class Element implements Comparable<Element>{
        private Interval interval;

        private int idx;

        public Element(Interval interval, int idx){
            this.interval = interval;
            this.idx  = idx;
        }

        public Interval getInterval(){
            return this.interval;
        }

        public int getIdx(){
            return idx;
        }

        @Override
        public int compareTo(Element o) {
            if(this.interval.getStart() < o.interval.getStart())
                return -1;
            else if(this.interval.getStart() == o.interval.getStart())
                return 0;
            else
                return 1;
        }
    }
    private int lowerBound(List<Element> data, int target) {
        int begin = 0;
        int end = data.size();

        while(begin < end) {
            int mid = (begin + end) / 2;

            if(data.get(mid).getInterval().getStart() >= target) {
                end = mid;
            }
            else {
                begin = mid + 1;
            }
        }
        return end;
    }

    public int[] findRightInterval(int[][] intervals) {
        List<Element> eleList = new ArrayList<>();
        int idx = 0;
        for(int[] interval: intervals){
            eleList.add(new Element(new Interval(interval[0],interval[1]),idx++));
        }
        Collections.sort(eleList);
        int[] ans = new int[intervals.length];

        for(int i = 0 ; i < eleList.size();i++){
            Element ele = eleList.get(i);
            int searchResult = lowerBound(eleList, ele.getInterval().getEnd());
            if(searchResult == eleList.size())
                ans[ele.getIdx()] = -1;
            else{
                ans[ele.getIdx()] = eleList.get(searchResult).getIdx();
            }
        }

        return ans;
    }
}
