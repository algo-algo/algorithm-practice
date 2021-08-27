package leetcode;

import sun.reflect.generics.tree.Tree;

import java.util.*;

public class leetcode199 {

    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(){};
        TreeNode(int val){this.val = val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        TreeNode tmp;
        if(root == null)
            return ans;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(q.size() != 0){
            int len = q.size();
            for(int i = 0; i < len;i++){
                tmp = q.poll();
                if(i == 0)
                    ans.add(tmp.val);
                if(tmp.right != null)
                    q.add(tmp.right);
                if(tmp.left != null)
                    q.add(tmp.left);
            }
        }
        return ans;
    }
}
