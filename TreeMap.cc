#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;

template<class K,class V>
class TreeMap {
    struct TreeNode {
        K key;
        V val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(K k, V v): key(k),val(v) {
            left = right = NULL;
        }
    };
    TreeNode *root;
public:
    TreeMap() {
        root = NULL;
    }
    
    void insert(K key, V val) {
        if(root == NULL) root = new TreeNode(key,val);
        else {
            TreeNode *cnt = root;
            while(cnt->key != key) { //not already there
                if(key > cnt->key) {
                    if(cnt->right == NULL) {
                        cnt->right = new TreeNode(key, val);
                        return;
                    }
                    cnt = cnt->right;
                } else {
                    if(cnt->left == NULL) {
                        cnt->left = new TreeNode(key, val);
                        return;
                    }
                    cnt = cnt->left;
                }
            }
        }
    }
    
    TreeNode* find(K key) {
        TreeNode *cnt = root;
        while(cnt) {
            if(cnt->key == key) return cnt;
            if(cnt->key > key) cnt = cnt->left;
            else cnt = cnt->right;
        }
        return NULL;
    }
    
    bool exists(K key) {
        TreeNode* node = find(key);
        return node != NULL;
    }
    
    V get(K key) {
        TreeNode* node = find(key);
        if(node == NULL) throw invalid_argument("Key not exists");
        return node->val;
    }
    
};

int main() {
    TreeMap<int,string> map;
    map.insert(12, "hel");
    map.insert(23,"wor");
    map.insert(3,"node");
    try {
        cout <<map.get(3)<<endl;
    } catch (exception& e) {
        cout <<e.what();
    }
    return 0;
}
