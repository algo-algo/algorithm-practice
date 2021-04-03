package leetcode;

import java.util.*;

public class TaskScheduler621 {
    public static void main(String[] args) {
        char[] tasks = {'A','A','A','B','B','B'};
        int n = 2;
        int output = 8;

//        char[] tasks = {'A','A','A','B','B','B'};
//        int n = 0;
//        int output = 6;

//        char[] tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
//        int n = 2;
//        int output = 16;

//        char[] tasks = {'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'D', 'A', 'D', 'E'};
//        int n = 2;
//        int output = 17;
        
        Solution solution = new Solution();
        int result = solution.leastInterval(tasks, n);

        System.out.println("output: " + output);
        System.out.println("result: " + result);
        System.out.println(output == result);

//        List<Solution.Task> taskList = new ArrayList<>();
//        taskList.add(new Solution.Task('A', 6));
//
//        Solution.Task task = taskList.get(0);
//        task.minus();
//        System.out.println(taskList.get(0));
    }

    static class Solution {
        public int leastInterval(char[] tasks, int n) {
            int taskLength = tasks.length;

            if (n == 0) {
                return taskLength;
            }

            Map<Character, Integer> taskMap = new HashMap<>();
            for (char task : tasks) {
                if (taskMap.containsKey(task)) {
                    int taskValue = taskMap.get(task);
                    taskMap.replace(task, taskValue + 1);
                } else {
                    taskMap.put(task, 1);
                }
            }

            List<Task> taskList = sortMapByValue(taskMap);
            int maxTaskIndex = 0;
            int idleCount = 0;
            for (int i = 0; i < taskList.size(); i++) {
                Task maxTask = taskList.get(maxTaskIndex);
                int nCount = 0;
                int nextTaskIndex = maxTaskIndex + 1;
                for (; nextTaskIndex < taskList.size(); nextTaskIndex++) {

                }
            }

            return taskLength + idleCount;
        }

        private List<Task> sortMapByValue(Map<Character, Integer> map) {
            List<Map.Entry<Character, Integer>> entries = new LinkedList<>(map.entrySet());
            entries.sort(Map.Entry.comparingByValue());

            List<Task> result = new ArrayList<>();
            for (int i = entries.size() - 1; i >= 0; i--) {
                Map.Entry<Character, Integer> entry = entries.get(i);
                result.add(new Task(entry.getKey(), entry.getValue()));
            }
            return result;
        }

        static class Task {
            private char alphabet;
            private int count;

            public Task(char alphabet, int count) {
                this.alphabet = alphabet;
                this.count = count;
            }

            public boolean isZeroTask() {
                return count == 0;
            }

            public void minus() {
                count--;
            }
        }
    }
}
