#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preorderIteratively(TreeNode *root) {
		if(root == NULL) return;
    	stack<TreeNode*> s;
		// visit(root);
		s.push(root);
		TreeNode *cnt = root;
		while(!s.empty()) {
			if(cnt != NULL) {
				visit(cnt);
				cnt = cnt->left;
				s.push(cnt);
			} else {
				s.pop();
				if(s.empty()) return;
				cnt = s.top();
				s.pop();
				s.push(cnt->right);
				cnt = cnt->right;
			}
		}
    }
	
	void preorderIterativelySimpler(TreeNode *root) {
		if(root == NULL) return;
    	stack<TreeNode *> s;
		s.push(root);
		while(!s.empty()) {
			TreeNode * t = s.top();
			visit(t);
			s.pop();
			if(t->right) s.push(t->right);
			if(t->left) s.push(t->left);
		}
	}
	
	void preorderRecercively(TreeNode *root) {
		if(root == NULL) return;
		visit(root);
		preorderRecercively(root->left);
		preorderRecercively(root->right);
	}
private:
	void visit(TreeNode *n) {
		cout << n->val <<" ";
	}
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    Solution s;
	// s.preorderRecercively(root);
   	// s.preorderIteratively(root);
	s.preorderIterativelySimpler(root);
    return 0;
}
