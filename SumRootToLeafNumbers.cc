class Solution {
public:
    int sumNumbers(TreeNode *root) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
	long sum=0, num=0;
	if(root==NULL)
	    return num;
	sumNumbers(root, sum, num);
	return sum;
    }

    void sumNumbers(TreeNode *root, long &sum, long num) {
	if(root == NULL) return;
	num = num*10+root->val;
	if(root->left==NULL && root->right==NULL) {
	    sum += num;
	    return ;
	}
	sumNumbers(root->left, sum, num);
	sumNumbers(root->right, sum, num);
	return;
    }
};
