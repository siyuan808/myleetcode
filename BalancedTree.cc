/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(!root) return true;
	if(height(root) == -1)
	    return false;
	return true;
    }

    int height(TreeNode *root) {
    	if(!root) return 0;
	int left = height(root->left);
	if(left==-1) return -1;
	int right = height(root->right);
	if(right== -1)
	    return -1;
	if( left-right <-1 || left-right > 1)
	    return -1;
	return left>right ? left+1 : right+1;
    }
};
