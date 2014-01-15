class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
	return buildNode(num, 0, num.size()-1);	
    }
    TreeNode *buildNode(vector<int> &num, int l, int h) {
	if(l>h) return NULL;
	int mid = (l+h)/2;
	TreeNode *root = new TreeNode(num[mid]);
	if(l<h) {
	    root->left = buildNode(num, l, mid-1);
	    root->right = buildNode(num, mid+1, h);
	}
	return root;
    }
};
