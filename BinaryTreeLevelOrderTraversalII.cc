#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
    	vector<vector<int> > result;
	if(root == NULL) return result; //remember to check validity
	vector<TreeNode *> *q1 = new vector<TreeNode*>();
	vector<TreeNode *> *q2 = new vector<TreeNode*>();
	q1->push_back(root);
	while(!q1->empty()) {
	    vector<int> levelVector;
	    q2->clear();
	    for(vector<TreeNode*>::iterator it = q1->begin();
	    	it != q1->end(); it++) {
		TreeNode *cur = *it;
		levelVector.push_back(cur->val);
		if(cur->left != NULL)
		    q2->push_back(cur->left);
		if(cur->right != NULL)
		    q2->push_back(cur->right);
	    }
	    result.insert(result.begin(), levelVector);
	    vector<TreeNode *> *tempQ = q1;
	    q1 = q2;
	    q2 = tempQ;
	}
        delete q1;
	delete q2;
	return result;
 }
 //another recursive solution
    vector<vector<int>> levelOrderFromBottom(TreeNode *root) {
        vector<vector<int>> rs;
	if(root== NULL) return rs;
	levelOrderAdd(rs, root, 0);
	std::reverse(rs.begin(), rs.end());
	return rs;
    }

    void levelOrderAdd(vector<vector<int>> &rs, TreeNode *root, int level) {
        if(root == NULL) return;
	if(level>=rs.size()) {
	    vector<int> newLevel;
	    rs.push_back(newLevel);
	}
	rs[level].push_back(root->val);
	levelOrderAdd(rs, root->left, level+1);
	levelOrderAdd(rs, root->right, level+1);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    Solution s;
    vector<vector<int> > levelOrder = s.levelOrderBottom(root);
    for(vector<vector<int> >::iterator it = levelOrder.begin();
	it!=levelOrder.end(); it++) {
	vector<int> level = *it;
	for(vector<int>::iterator lit = level.begin();
		lit!=level.end(); lit++) {
		int a = *lit;
		cout <<a<< " ";
	}
	cout <<endl;
    }
    return 0;
}
