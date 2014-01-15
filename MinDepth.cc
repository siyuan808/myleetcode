class Solution {
public:
    int minDepth(TreeNode *root) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
		if(root == NULL) return 0;
		return helper(root);
    }

    int helper(TreeNode * root) {
		if(root==NULL) return 0;
	    int leftHeight = minDepth(root->left);
		int rightHeight = minDepth(root->right);
	 	if(leftHeight > 0 && rightHeight>0)
		    return leftHeight < rightHeight? leftHeight+1 : rightHeight+1;
		if(leftHeight == 0)
		    return rightHeight+1;
		if(rightHeight == 0)
		    return leftHeight+1;
    }

    int minDepth(TreeNode * root) {
	//the above recursive method is not efficient enough. 
	//It will touch every node in the tree.
	//This BST method will only the nodes above the level on which
	//the first leaf is.
		if(root==NULL) return 0;
		if(root->left==NULL && root->right==NULL) return 1;
		int rs = 1;
		queue<TreeNode *> q;
		q.push(root);
		int levelCount =1;
		while(!q.empty()){
		    int count = levelCount;
		    levelCount = 0;
		    rs++;
		    for(int i=0; i< count; i++){
		        TreeNode *first = q.front();
				q.pop();
				if(first->left!=NULL) {
				    if(first->left->left==NULL && first->left->right==NULL)
				    	return rs;
				    q.push(first->left);
				    levelCount++;
				}
				if(first->right!=NULL) {
				    if(first->right->left==NULL && first->right->right==NULL)
				        return rs;
				    q.push(first->right);
				    levelCount++;
				}
		    }
		}
		return rs;
    }
};
