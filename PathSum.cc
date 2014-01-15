class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
	// return false, when the tree is empty;
	if(root == NULL) return false;
	if(root->left==NULL && root->right==NULL)
		return root->val==sum;
	bool lv = hasPathSum(root->left, sum - root->val);
	if(lv) return true;
	bool rv = hasPathSum(root->right, sum - root->val);
	return rv;
    }
};
