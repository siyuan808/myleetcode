ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
	//         // DO NOT write int main() function
    if(head == NULL || n < 1) return head;
    ListNode *prev = head, *ptr = head;
    int i = 1;
    //first find the n+1 node from end
    while(ptr->next!=NULL) {
	if(i >= n+1) {
	    prev = prev->next;
	} else {
	    i++;
	}
	ptr = ptr->next;
    }

    if(i == n) {
	//remove the head;
	ptr = head;
	head = head->next;
	delete ptr;
    } else {
	ptr = prev->next;
	prev->next = ptr->next;
	delete ptr;
    }
    return head;
}
