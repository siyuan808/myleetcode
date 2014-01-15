class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
	if(head == NULL) return head;
	ListNode *current = head;
	while(current && current->next) {
	    ListNode *nxt = current->next;
	    if(nxt->val == current->val) {
	        //duplicate, remove current.next
		current->next = nxt->next;
		delete nxt;
	    } else 
	        current = nxt;
	}
	return head;
    }
};
