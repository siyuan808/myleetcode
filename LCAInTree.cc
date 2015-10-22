#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

class TreeNode {
public:
    int val;
    vector<TreeNode*> children;

    TreeNode(int v): val(v) {}
    void add(TreeNode *t) {
        children.push_back(t);
    }
};

TreeNode* helper(TreeNode* root, TreeNode *p, TreeNode *q, bool &found) {
    if(root == NULL || root == p || root == q) return root;
    
    TreeNode* res = NULL;
    for(TreeNode* child : root->children) {
        TreeNode *anc = helper(child, p, q, found);
        if(found) return anc;
        if(anc) {
            if(res == NULL) res = anc;
            else {
                found = true;
                return root;
            }
        }
    }
    return res;
}

TreeNode* LCA(TreeNode* root, TreeNode *p, TreeNode * q) {
    //assume p and q are all in the tree
    bool found = false;
    return helper(root, p, q, found);
}
int main() {
    TreeNode* root = new TreeNode(0);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    
    root->add(n1); root->add(n2);
    n1->add(n3);
    n2->add(n4); n2->add(n5);
    n4->add(n6);
    
    TreeNode* lca = LCA(root, n6, n3);
    if(lca == NULL) cout <<"NOT FOUND";
    else cout <<lca->val;
    return 0;
}
