#include <iostream>
//Given two linked lists representing two integers in forwarding order
//write function to add them and return a new list

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *l) {
    while(l != NULL) {
    	cout << l->val;
	if(l->next != NULL) cout <<" -> ";
	l = l->next;
    }
    cout <<endl;
}

struct Result {
    ListNode *resultNode;
    int carry;
    Result(ListNode *res, int c) : resultNode(res), carry(c) {}
    ~Result() {};
};

Result *addNodes(ListNode *l1, ListNode *l2, int n, int diff) {
    if(l1 == NULL && l2 == NULL) 
    	return new Result(NULL, 0);
    Result *next = NULL;
    int sum = 0;
    if(n < diff) {
    	next = addNodes(l1->next, l2, n+1, diff);
    	sum = l1->val + next->carry;
    }
    else {
    	next = addNodes(l1->next, l2->next, n+1, diff);
		sum = l1->val + l2->val + next->carry;
    }
    ListNode *lNode = new ListNode(sum % 10);
    lNode->next = next->resultNode;
    delete next;
    return new Result(lNode, sum / 10);
}

ListNode *addTwoList(ListNode *l1, ListNode *l2) {
    int len1 = 0, len2 = 0;
    ListNode *l1Node = l1, *l2Node = l2;
    while(l1Node != NULL) {
		len1++; 
		l1Node = l1Node->next;
    }
    while(l2Node != NULL) {
		len2++; 
		l2Node = l2Node->next;
    }

    Result *result = NULL;
    if(len1 >= len2) 
    	result = addNodes(l1, l2, 0, len1 - len2);
    else 
    	result = addNodes(l2, l1, 0, len2 - len1);

    ListNode *ptr = result->resultNode;
    delete result;
    if(result->carry > 0) {
        ListNode *head = new ListNode(result->carry);
		head->next = ptr;
		return head;
    } else 
    	return ptr;
}

int main() {
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(9);
    ListNode *l2 = new ListNode(8);
    l2->next = new ListNode(1);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(0);    
    printList(l1);
    cout <<" + "<<endl;
    printList(l2);
    cout <<" = " <<endl;
    printList(addTwoList(l1, l2));
    return 0;
}
