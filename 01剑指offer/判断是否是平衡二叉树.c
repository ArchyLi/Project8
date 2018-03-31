//这个做法感觉蠢了。。
#ifdef 1
bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == NULL)
		return true;
	int leftHeight = height(pRoot->left);
	int rightHeight = height(pRoot->right);
	if (leftHeight - rightHeight >= 2 || leftHeight - rightHeight <= -2)
		return false;
	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}
int height(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	int lefth = height(pRoot->left);
	int righth = height(pRoot->right);
	return lefth > righth ? lefth + 1 : righth + 1;
}
////别人做法
bool IsBalanced(TreeNode *root, int & dep) {
	if (root == NULL) {
		return true;
	}
	int left = 0;
	int right = 0;
	if (IsBalanced(root->left, left) && IsBalanced(root->right, right)) {
		int dif = left - right;
		if (dif < -1 || dif >1)
			return false;
		dep = (left > right ? left : right) + 1;
		return true;
	}
	return false;
}
bool IsBalanced_Solution(TreeNode* pRoot) {
	int dep = 0;
	return IsBalanced(pRoot, dep);
}
