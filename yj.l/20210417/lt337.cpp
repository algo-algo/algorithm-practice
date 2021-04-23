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

class CheckTree {
public:
    int sum;
    bool check;
    CheckTree *left;
    CheckTree *right;
    CheckTree() : sum(0), check(false), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* cur, CheckTree* cCur, bool prev) {
        int sum = 0;
        if (prev) {
            if (cur->left != nullptr) sum += dfs(cur->left, cCur->left, false);
            if (cur->right != nullptr) sum += dfs(cur->right, cCur->right, false);
            return sum;
        }
        else {
            if (cCur->check) return cCur->sum;
            int tmpT = cur->val, tmpF = 0;

            if (cur->left != nullptr) {
                tmpT += dfs(cur->left, cCur->left, true);
                tmpF += dfs(cur->left, cCur->left, false);
            }
            if (cur->right != nullptr) {
                tmpT += dfs(cur->right, cCur->right, true);
                tmpF += dfs(cur->right, cCur->right, false);
            }

            sum = tmpT > tmpF ? tmpT : tmpF;
            cCur->sum = sum;
            cCur->check = true;
            return sum;
        }
    }
    void setCheckTree(TreeNode* root, CheckTree* cRoot) {
        if (root->left != nullptr) {
            cRoot->left = new CheckTree();
            setCheckTree(root->left, cRoot->left);
        }
        if (root->right != nullptr) {
            cRoot->right = new CheckTree();
            setCheckTree(root->right, cRoot->right);
        }
    }
public:
    int rob(TreeNode* root) {
        CheckTree* cRoot = new CheckTree();
        setCheckTree(root, cRoot);

        return dfs(root, cRoot, false);
    }
};

//int main() {
//    return 0;
//}