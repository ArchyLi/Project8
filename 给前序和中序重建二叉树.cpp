struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
		int vinsize = vin.size();
		if (vinsize == 0)
			return NULL;
		int get = 0;
		//根结点为前序遍历的第一个结点
		TreeNode* root = new TreeNode(pre[0]);
		//找到中序遍历的根结点的为止
		for (int i = 0; i < vinsize; i++)
		{
			if (pre[0] == vin[i])
			{
				get = i;
				break;
			}
		}
		//根结点的左节点在二叉树的左边，根结点的右结点在二叉树的右边
		std::vector<int> preleft, preright, vinleft, vinright;
		for (int i = 0; i < get; i++)
		{
			preleft.push_back(pre[i + 1]);
			vinleft.push_back(vin[i]);
		}
		for (int i = get + 1; i < vinsize; i++)
		{
			vinright.push_back(vin[i]);
			preright.push_back(pre[i]);
		}
		//找到前序和中序遍历的左边和右边子树的结点
		root->left = reConstructBinaryTree(preleft, vinleft);
		root->right = reConstructBinaryTree(preright, vinright);
		return root;
	}
};
