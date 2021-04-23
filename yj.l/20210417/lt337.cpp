#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeNodeExt : TreeNode {
    int sum;
    bool
};

class Solution {
    int dfs(TreeNode* cur, bool prev) {
        int sum = 0;
        if (prev) {
            if (cur->left != nullptr) sum += dfs(cur->left, false);
            if (cur->right != nullptr) sum += dfs(cur->right, false);
            return sum;
        }
        else {
            if (cur->check) return cur->sum;
            if (cur->left != nullptr) sum += max(dfs(cur->left, true), dfs(cur->left, false));
            if (cur->right != nullptr) sum += max(dfs(cur->right, true), dfs(cur->right, false));
            cur->sum = sum;
            cur->check = true;
            return sum;
        }
    }
public:
    int rob(TreeNode* root) {
        return dfs(root, false);
    }
};

int main() {
    return 0;
}