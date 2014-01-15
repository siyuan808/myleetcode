class Solution {
public:
    int maxPathSum(TreeNode *root) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
  	int max_sum=INT_MIN;
	maxSum(root, max_sum);
	return max_sum;
    }

    int maxSum(TreeNode *root, int &max_sum) {
	if(root == NULL) return 0;
	int l = maxSum(root->left, max_sum);
	int r = maxSum(root->right, max_sum);
	int cSum = max(root->val, max(l+root->val, r+root->val));
	max_sum = max(max_sum, max(cSum, root-val+l+r));
	return cSum;
    }
};
