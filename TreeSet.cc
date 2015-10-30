#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;

class TreeMap {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int v): val(v) {
            left = right = NULL;
        }
    };
    TreeNode *root;
public:
    TreeMap() {
        root = NULL;
    }
    
    void insert(int val) {
        if(root == NULL) root = new TreeNode(val);
        else {
            TreeNode *cnt = root;
            while(cnt->val != val) { //not already there
                if(val > cnt->val) {
                    if(cnt->right == NULL) {
                        cnt->right = new TreeNode(val);
                        return;
                    }
                    cnt = cnt->right;
                } else {
                    if(cnt->left == NULL) {
                        cnt->left = new TreeNode(val);
                        return;
                    }
                    cnt = cnt->left;
                }
            }
        }
    }
    
    bool find(int val) {
        TreeNode *cnt = root;
        while(cnt) {
            if(cnt->val == val) return true;
            if(cnt->val > val) cnt = cnt->left;
            else cnt = cnt->right;
        }
        return false;
    }
    
};

int main() {
    TreeMap map;
    map.insert(12);
    map.insert(23);
    map.insert(3);
    cout <<map.find(5)<<endl;
    return 0;
}
