package leetcode;

import java.util.*;

public class HouseRobberIII337 {
    public static void main(String[] args) {
//        Integer[] numbers = {3, 2, 3, null, 3, null, 1};

//        Integer[] numbers = {3, 4, 5, 1, 3, null, 1};

        Integer[] numbers = {4, 1, null, 2, null, 3};

        TreeNode root = new TreeNode(numbers[0]);
        List<TreeNode> treeNodes = new ArrayList<>();
        treeNodes.add(root);
        for (int i = 1; i < numbers.length; i++) {
            TreeNode treeNode;
            if (i % 2 == 0) {
                int index = (i / 2) - 1;
                treeNode = treeNodes.get(index);
                while (Objects.isNull(treeNode)) {
                    treeNode = treeNodes.get(++index);
                }
            } else {
                int index = i / 2;
                treeNode = treeNodes.get(index);
                while (Objects.isNull(treeNode)) {
                    treeNode = treeNodes.get(++index);
                }
            }
            if (i % 2 == 1) {
                if (Objects.isNull(numbers[i])) {
                    treeNode.left = null;
                    treeNodes.add(null);
                } else {
                    TreeNode left = new TreeNode(numbers[i]);
                    treeNode.left = left;
                    treeNodes.add(left);
                }
            } else {
                if (Objects.isNull(numbers[i])) {
                    treeNode.right = null;
                    treeNodes.add(null);
                } else {
                    TreeNode right = new TreeNode(numbers[i]);
                    treeNode.right = right;
                    treeNodes.add(right);
                }
            }
        }

        Solution solution = new Solution();
        int answer = solution.rob(root);
        System.out.println(answer);
    }

    static class Solution {
        public int rob(TreeNode root) {
            Money money = dfs(root);

            return money.getMaxRobbedMoney();
        }

        private Money dfs(TreeNode treeNode) {
            if (Objects.isNull(treeNode)) {
                return Money.emptyMoney();
            }

            Money leftMoneySum = dfs(treeNode.left);
            Money rightMoneySum = dfs(treeNode.right);

            int robbedMoney = treeNode.val + leftMoneySum.getUnRobbedMoney() + rightMoneySum.getUnRobbedMoney();
            int unRobbedMoney = leftMoneySum.getMaxRobbedMoney() + rightMoneySum.getMaxRobbedMoney();

            return new Money(robbedMoney, unRobbedMoney);
        }

        static class Money {
            private final int robbedMoney;
            private final int unRobbedMoney;

            public Money(int robbedMoney, int unRobbedMoney) {
                this.robbedMoney = robbedMoney;
                this.unRobbedMoney = unRobbedMoney;
            }

            public static Money emptyMoney() {
                return new Money(0, 0);
            }

            public int getMaxRobbedMoney() {
                return Math.max(this.robbedMoney, this.unRobbedMoney);
            }

            public int getUnRobbedMoney() {
                return unRobbedMoney;
            }
        }
    }

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
