class Solution {
public:
    bool isValidBST(TreeNode *root) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
	//if(root == NULL) return false;
	int min = INT_MIN, max = INT_MAX;
	return valid(root, min, max);
    }

    bool valid(TreeNode *root, int min, int max) {
	if(root==NULL) return true;
	if(root->val >= max || root->val <= min) 
	    return false;
	if(valid(root->left, min, root->val))
	    return valid(root->right, root->val, max);
	else 
	    return false;
    }

    //The following is an non-recursive method 
    bool isValidBST(TreeNode *root) {
	//if we check the nodes in oderly, the values should be in an non-decresing order
	if(root == NULL) return true;
	int min = INT_MIN;
	stack<TreeNode *> s;
	s.push(root);
	TreeNode *cnt = root;
	while(!s.empty()) {
	    if(cnt != NULL) {
		cnt = cnt->left;
		s.push(cnt);
	    } else {
		s.pop();
		if(s.empty()) return true;
		cnt = s.top();
		s.pop();
		if(cnt->val <= min) return false;
		min = cnt->val;
		cnt = cnt->right;
		s.push(cnt);
	    }
	}
	return true;
    }

    //Solution 3: create a new structure to change convert the recursion method
    struct Node {
	TreeNode *treeNode;
	int min;
	int max;
	Node(TreeNode *n, int mi, int ma) {
	    treeNode = n;
	    min = mi;
	    max = ma;
	}
    };
    
    bool isValidBST(TreeNode *root) {
	if(root == NULL) return true;
	Node *cnt = new Node(root, INT_MIN, INT_MAX);
	stack<Node *> s;
	s.push(cnt);
	while(!s.empty()) {
	    if(cnt->treeNode != NULL) {
		Node *left = new Node(cnt->treeNode->left, cnt->min, cnt->treeNode->val);
		s.push(left);
		cnt = left;
	    } else {
	    	Node *top = s.top();
		s.pop();
		delete top;
		if(s.empty()) return true;
		top = s.top();
		s.pop();
		//checking 
		if(top->treeNode->val <= top->min || top->treeNode->val >= max) {
		    //clean up the stack
		    delete top;
		    while(!s.empty()){
			top = s.top();
			s.pop();
			delete top;
		    }
		    return false;
		} else {
		    delete top;
		    Node *right = new Node(top->treeNode->right, top->treeNode->val, top->max);
		    cnt = right;
		    s.push(cnt);
		}
	   }
	}
	return true;
    }
};
