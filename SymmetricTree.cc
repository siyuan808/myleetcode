ass Solution {
public:
    bool isSymmetric(TreeNode *root) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
  	if(root == NULL) return false;
	return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode*right) {
	if(left==NULL && right==NULL) return true;
	if(left==NULL && right!=NULL || left!=NULL && right==NULL) return false;
	//left != NULL && right !=NULL
	return (left->val==right->val) && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

