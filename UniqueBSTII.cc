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
    vector<TreeNode *> generateTrees(int n) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
	return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int s, int e) {
	vector<TreeNode*> result;
	if(s>e) {
	    result.push_back(NULL);
	    return result;
	}

	for(int i=s; i<=e; i++) {
	    vector<TreeNode *> leftNodes = generateTrees(s, i-1);
	    vector<TreeNode *> rightNodes = generateTrees(i+1, e);

	    for(int j=0; j<leftNodes.size(); ++j)
	    	for(int k=0; k<rightNodes.size(); k++) {
		    TreeNode *root = new TreeNode(i);
		    root->left = leftNodes[j];
		    root->right = rightNodes[k];
		    result.push_back(root);
		}
	}
	return result;
    }
};
