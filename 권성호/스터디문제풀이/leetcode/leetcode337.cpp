class Solution {
public:

	int rob(TreeNode* root) {
        
        if(root == nullptr)
            return 0;
        
        rob(root->left);
        rob(root->right);


		int max1 = root->val;
		if (root->left != nullptr && root->left->left != nullptr)
			max1 += root->left->left->val;
		if (root->left != nullptr && root->left->right != nullptr)
			max1 += root->left->right->val;
		if (root->right != nullptr && root->right->left != nullptr)
			max1 += root->right->left->val;
		if (root->right != nullptr && root->right->right != nullptr)
			max1 += root->right->right->val;

		int max2 = 0;
		if (root->left != nullptr)
			max2 += root->left->val;
		if (root->right != nullptr)
			max2 += root->right->val;

        root->val = max1 > max2 ? max1 : max2;

		return root->val;
	}
};