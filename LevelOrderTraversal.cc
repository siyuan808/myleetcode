class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
    	vector<vector<int>> res;
	levelOrderModify(root, res, 0);
	return res;
    }

    void levelOrderModify(TreeNode *root, vector<vector<int>> &res, int level) {
	if(root == NULL) return;
	if(level >= res.size()) {
	    vector<int> v;
	    res.push_back(v);
	}
	res[level].push_back(root->val);
	levelOrderModify(root->left, res, level+1);
	levelOrderModify(root->right, res, level+1);
    }

};
