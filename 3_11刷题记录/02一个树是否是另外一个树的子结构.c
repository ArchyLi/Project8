#include <stdio.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool ret = false;
	if (pRoot1 != NULL&&pRoot2 != NULL)
	{
		//如果结点的值相等，则进入子结构的判断
		if (pRoot1->val == pRoot2->val)
			ret = HasTree(pRoot1, pRoot2);
		if (!ret)
			//主树进入左节点判断
			ret = HasSubtree(pRoot1->left, pRoot2);
		if (!ret)
			//主树进入右结点判断
			ret = HasSubtree(pRoot1->right, pRoot2);
	}
	return ret;
}
//子结构判断程序
bool HasTree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//此处表示需要判断的树已经走完，是子结构
	if (pRoot2 == NULL)
	{
		return true;
	}
	//此处说明pRoot2不为空同时主树为空，所以结果不是子结构
	if (pRoot1 == NULL)
	{
		return false;
	}
	//如果这两个结点的值不想等，则返回false
	if (pRoot1->val != pRoot2->val)
	{
		return false;
	}
	return HasTree(pRoot1->left, pRoot2->left) && HasTree(pRoot1->right, pRoot2->right);
}
