/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
Sort a linked list in O(n log n) time using constant space complexity.
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        //base case
        if(head == NULL || head->next == NULL) 
            return head;
        
        //split the list from the middle
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *head2 = slow->next;
        slow->next = NULL; //break the list
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(head2);
        
        //merge the sorted two list
        ListNode *newHead, *tail;
        if(l1->val < l2->val) {
            newHead = l1;
            l1 = l1->next;
        } else {
            newHead = l2;
            l2 = l2->next;
        }
        tail = newHead;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) 
            tail->next = l1;
        if(l2) 
            tail->next = l2;
        
        return newHead;
    }
};