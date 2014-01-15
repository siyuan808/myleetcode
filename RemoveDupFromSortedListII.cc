class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
  	if(!head || !head->next) return head;
	ListNode *prev = head, *cur = head, *next = head->next;
	bool dupCur = false;
	while(next) {
	    if(cur->val == next->val) {
	   	cur->next = next->next;
		delete next;
		next = cur->next;
		dupCur = true;
	    } else {
	    	if(dupCur) { //delete cur
		    if(cur == head) {
		    	head = head->next;
			delete cur;
			cur = head;
			prev = head;
			next = head->next;
		    } else {
			prev->next = next;
			delete cur;
			cur = prev->next;
			next = cur->next;
		   }
		   dupCur = false;
	 	} else {
		   prev = cur;
		   cur = next;
		   next = next->next;
		}
	    }
	} 
	if(dupCur) {
	    if(cur == head) {
	    	delete head;
		head = NULL;
	    } else {
	    	prev->next = NULL;
		delete cur;
	    }
	}
	return head;
    }


/*Another recursive solution*/
/*    if(head == NULL){
	return head;
    } 
    bool dup = false;
    while(head->next && head->val = head->next->val) {
    	ListNode *c = head;
	head = head->next;
	delete c;
	dup = true;
    }
    if(dup) {
    	ListNode *c = head;
	head = deleteDuplicates(head->next);
	delete c;
    } else {
    	head->next = deleteDuplicates(head->next);
    }
    return head;
*/
}
