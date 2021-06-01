
class Solution {

	
private:
	int ans;
	void DFS(TreeNode* root, int depth) {
		if (root == nullptr) {
			ans = ans > depth ? ans : depth;
			return;
		}

		DFS(root->left, depth + 1);
		DFS(root->right, depth + 1);
	}

public:
	int maxDepth(TreeNode* root) {
		// DFS로 탐색하면서 종료조건에서 가장 깊은 깊이로 정답 업데이트 하는 방식
		ans = 0;
		DFS(root, 0);
		return ans;
	}
};
