#include <stdio.h>
#include <stack>
	void Mirror(TreeNode *pRoot) {
		//if (pRoot == NULL) {
		//	return;
		//}
		//TreeNode *tmp = pRoot->left;
		//pRoot->left = pRoot->right;
		//pRoot->right = tmp;
		//Mirror(pRoot->left);
		//Mirror(pRoot->right);
		std::stack<TreeNode*> s;
		if (pRoot == NULL) {
			return;
		}
		//首先压入根结点
		s.push(pRoot);
		//为空则结束
		while (!s.empty())
		{
			TreeNode* root = s.top();
			s.pop();
			//只要左右有一个就交换
			if (root->left || root->right)
			{
				TreeNode* temp = root->left;
				root->left = root->right;
				root->right = temp;
			}
			//压入左右结点
			if (root->left)
				s.push(root->left);
			if (root->right)
				s.push(root->right);
		}

	}
