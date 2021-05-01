package boj;

import java.io.*;
import java.util.*;

public class Boj1949 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        String line = br.readLine();
        String[] lines = line.split(" ");
        int[] people = new int[N];
        for (int i = 0; i < N; i++) {
            people[i] = Integer.parseInt(lines[i]);
        }

        TreeNode[] treeNodes = new TreeNode[N];
        for (int i = 0; i < N - 1; i++) {
            line = br.readLine();
            lines = line.split(" ");
            int leftNodeIndex = Integer.parseInt(lines[0]) - 1;
            int rightNodeIndex = Integer.parseInt(lines[1]) - 1;
            TreeNode leftNode = getNodes(treeNodes, leftNodeIndex);
            TreeNode rightNode = getNodes(treeNodes, rightNodeIndex);
            TreeNode.addNode(leftNode, rightNode);
            addNode(treeNodes, leftNodeIndex, leftNode);
            addNode(treeNodes, rightNodeIndex, rightNode);
        }

        boolean[] visited = new boolean[N];
        int answer = recursiveDfs(people, treeNodes, visited);

        bw.write(String.valueOf(answer));

        bw.flush();
        bw.close();
        br.close();
    }

    private static TreeNode getNodes(TreeNode[] treeNodes, int nodeIndex) {
        if (Objects.isNull(treeNodes[nodeIndex])) {
            return new TreeNode(nodeIndex);
        }
        return treeNodes[nodeIndex];
    }

    private static void addNode(TreeNode[] treeNodes, int nodeIndex, TreeNode treeNode) {
        if (Objects.isNull(treeNodes[nodeIndex])) {
            treeNodes[nodeIndex] = treeNode;
        }
    }

    private static int recursiveDfs(int[] people, TreeNode[] treeNodes, boolean[] visited) {
        TreeNode root = treeNodes[0];
        People maxPeople = dfs(people, treeNodes, visited, root);

        return maxPeople.getMaxPeople();
    }

    private static People dfs(int[] people, TreeNode[] treeNodes, boolean[] visited, TreeNode treeNode) {
        visited[treeNode.index] = true;

        List<People> peoples = new ArrayList<>();
        Set<Integer> adjacentIndexes = treeNode.adjacentIndexes;
        if (adjacentIndexes.size() == 0) {
            return new People(people[treeNode.index], 0);
        }
        for (int index : adjacentIndexes) {
            if (!visited[index]) {
                peoples.add(dfs(people, treeNodes, visited, treeNodes[index]));
            }
        }

        int takeThisPeople = people[treeNode.index] + sumUnTakeThisPeople(peoples);
        int unTakeThisPeople = sumMaxPeoples(peoples);

        return new People(takeThisPeople, unTakeThisPeople);
    }

    private static int sumMaxPeoples(List<People> peoples) {
        int sum = 0;
        for (People people : peoples) {
            sum += people.getMaxPeople();
        }

        return sum;
    }

    private static int sumUnTakeThisPeople(List<People> peoples) {
        int sum = 0;
        for (People people : peoples) {
            sum += people.unTakeThisPeople;
        }

        return sum;
    }

    static class TreeNode {
        private int index;
        private final Set<Integer> adjacentIndexes = new HashSet<>();

        public TreeNode(int index) {
            this.index = index;
        }

        public static void addNode(TreeNode leftNode, TreeNode rightNode) {
            leftNode.adjacentIndexes.add(rightNode.index);
            rightNode.adjacentIndexes.add(leftNode.index);
        }
    }

    static class People {
        private int takeThisPeople;
        private int unTakeThisPeople;

        public People(int takeThisPeople, int unTakeThisPeople) {
            this.takeThisPeople = takeThisPeople;
            this.unTakeThisPeople = unTakeThisPeople;
        }

        public int getMaxPeople() {
            return Math.max(takeThisPeople, unTakeThisPeople);
        }
    }
}
