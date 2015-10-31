#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int v): val(v){}
    void add(TreeNode* child) {
        children.push_back(child);
    }
    bool isPrimitive() {
        return children.empty();
    }
};

class Tree {
    TreeNode* root;
public:
    Tree() { //[1,[2,3],[[4]]]
        root = new TreeNode(0);
        root->add(new TreeNode(1));
        TreeNode *n2 = new TreeNode(0);
        n2->add(new TreeNode(2));
        n2->add(new TreeNode(3));
        root->add(n2);
        TreeNode *n3 = new TreeNode(0);
        TreeNode *n4 = new TreeNode(0);
        n4->add(new TreeNode(4));
        n3->add(n4);
        root->add(n3);
    }
    int weightSum() {
        int res = 0;
        cal(root, 0, res);
        return res;
    }
    void cal(TreeNode* root, int level, int& res) {
        if(root->isPrimitive()) {
            res += root->val * level;
            return;
        }
        for(TreeNode* child : root->children) {
            cal(child, level + 1, res);
        }
    }
};

int main() {
    Tree t;
    cout <<t.weightSum();
    return 0;
}
