/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversalRecursive(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		vector<int> res;
        if(root == NULL) return res;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);

        for(auto l : left) 
            res.push_back(l);

        for(auto r : right) 
            res.push_back(r);

        res.push_back(root->val);

        return res;
    }
	
	vector<int> postorderTraversalIterative(TreeNode *root) {
		vector<int> res;
        if(root == NULL) return res;
		
		stack<TreeNode *> s;
		TreeNode *cnt, *prev = NULL;
		s.push(root);

		while(!s.empty()) {
			cnt = s.top();
			if(!prev || prev->left == cnt || prev->right == cnt) {
			    //moving down;
			    if(cnt->left)
			        s.push(cnt->left);
			    else if(cnt->right)
			        s.push(cnt->right);
			 //   else {
			 //       res.push_back(cnt->val);
			 //       s.pop();
			 //   }
			} else if(cnt->left == prev) {
			    if(cnt->right)
			        s.push(cnt->right);
			 //   else {
			 //       res.push_back(cnt->val);
			 //       s.pop();
			 //   }
			} 
			else {// if (cnt->right == prev) {
			    res.push_back(cnt->val);
		        s.pop();
			}
			prev = cnt;
		}
		return res;
	}
};