ListNode *partition(ListNode *head, int x) {
    if(head == NULL) return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *partPtr = dummy, *prev = dummy;

    while(prev->next) {
		if(prev->next->val < x) {
		    ListNode *temp = prev->next;
		    prev->next = temp->next;
		    temp->next = partPtr->next;
		    partPtr->next = temp;
		    if(prev == partPtr) //in case that after the exchange the list remains the same
		        prev = prev->next;
		    partPtr = partPtr->next;
		} else {
		    prev = prev->next;
		}	
    }
	head = dummy->next;
	delete dummy;
    return head;
}
