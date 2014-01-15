class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Given two list representing two numbers in reverse order,
    // return a list that representing the sum of the two numbers
        ListNode *head = new ListNode(0);
		ListNode *tail = head;
		int a0 = 0;
		int a1, a2;
		ListNode *l1ptr = l1, *l2ptr = l2;
		while(l1ptr != NULL || l2ptr != NULL) {
		    if(l1ptr == NULL) 
			a1 = 0;
		    else {
			a1 = l1ptr->val;
			l1ptr = l1ptr->next;
		    }

		    if(l2ptr == NULL) 
		        a2 = 0;
		    else {
			a2 = l2ptr->val;
			l2ptr = l2ptr->next;
		    }

		    int sum0 = a0+a1+a2;
		    tail->next = new ListNode(sum0%10);
		    tail = tail->next;
		    a0 = (sum0>=10)?1:0;
		}
		if(a0>0)
		    tail->next = new ListNode(a0);
		tail = head->next;
		delete head;
		return tail;
    }
};
