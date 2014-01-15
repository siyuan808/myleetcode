class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
  	if(m<1 || m >= n) return head;
	ListNode *dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode *preM, *pre = dummyHead;

	for(int i=1; i<=n; i++) {
	    if(i==m) preM = pre;
	    
	    if( i>m && i<=n) {
	 	pre->next = head->next;
		head->next = preM->next;
		preM->next = head;
		head = pre;
	    }

	    pre = head;
	    head = head->next;
	}
	return dummyHead->next;
    }
};
