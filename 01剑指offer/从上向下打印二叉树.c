vector<int> PrintFromTopToBottom(TreeNode* root) {
	queue<TreeNode*> q;
	vector<int> v;
	q.push(root);
	while (!q.empty())
	{
		root = q.front();
		q.pop();
		if (NULL == root)continue;
		v.push_back(root->val);
		q.push(root->left);
		q.push(root->right);
	}
	return v;
}
