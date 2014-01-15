ass Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
        int len = 0;
		ListNode *lnode = head;
		while(lnode != NULL) {
		    len++;
		    lnode = lnode->next;
		}
		return sortedListToBST(head, 0, len-1);
		//return sortedListToBST(head, len);
    }

    TreeNode *sortedListToBST(ListNode *&head, int start, int end) {
		if(start>end) return NULL;
		int mid = start+(end-start)/2;
		TreeNode *leftChild = sortedListToBST(head, start, mid-1);
		TreeNode *node = new TreeNode(head->val);
		node->left = leftChild;
		head = head->next;
		node->right = sortedListToBST(head, mid+1, end);
		return node;
    }
	
    TreeNode *sortedListToBST(ListNode *&head, int n) {
        if(n<=0) return NULL;        
        TreeNode *leftChild = sortedListToBST(head,n/2);
        TreeNode *node = new TreeNode(head->val);
        node->left = leftChild;
        head = head->next;
        node->right = sortedListToBST(head, (n%2==0)?n/2-1:n/2);
        return node;
    }
};
