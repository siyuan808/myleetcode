class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
        vector<vector<int>> rs;
        if(root==NULL) return rs;
	if(root->left==NULL && root->right==NULL) {
	    if(root->val==sum) {
		//find a path
		vector<int> onePath;
		onePath.push_back(root->val);
		rs.push_back(onePath);
	    }
	    return rs;
	}
	vector<vector<int>> lrs = pathSum(root->left, sum - root->val);
	vector<vector<int>> rrs = pathSum(root->right, sum - root->val);
	//now merge the two vectors. 
	if(!lrs.empty()) {
	//add current node to the path
	    for(int i=0; i<lrs.size(); i++) 
	        lrs[i].insert(lrs[i].begin(), root->val);
	}
	if(!rrs.empty()) {
	    for(int i=0; i<rrs.size(); i++)
	    	rrs[i].insert(rrs[i].begin(), root->val);
	}
	if(lrs.empty()) return rrs;
	if(rrs.empty()) return lrs;
	//now append rrs to lrs
	for(int i=0; i<rrs.size(); i++)
	    lrs.push_back(rrs[i]);
	return lrs;
    }

    //The above method create from bottom to up
    //This one create from top downward
    //Note that the vector.push_back() method copies the object
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
	vector<vector<int>> rs;
	vector<int> path;
	findSum(root, sum, rs, path);
	return rs;
    }
    
    void findSum(TreeNode *root, int sum, vector<vector<int>> &vvc, vector<int> &ivc) {
	if(root==NULL) return;
	ivc.push_back(root->val);
	if(root->left==NULL && root->right==NULL && root->val==sum) {
	     vvc.push_back(ivc);
	    ivc.pop_back();
	     return;
	}
	if(root->left) findSum(root->left, sum-root->val, vvc, ivc);
	if(root->right) findSum(root->right, sum-root->val, vvc, ivc);
	ivc.pop_back();
    }
};

