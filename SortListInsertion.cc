/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
Sort a linked list using insertion sort. O(n^2)
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *last = head, *cnt = head->next;
        while(cnt) {
            if(cnt->val >= last->val) {
                last = cnt;
                cnt = cnt->next;
            } else {
                //mv cnt forward;
                last->next = cnt->next;
                if(cnt->val <= head->val) {
                    // update head;
                    cnt->next = head;
                    head = cnt;
                } else {
                    ListNode *lt = head;
                    while(lt->next->val < cnt->val) 
                       lt = lt->next;
                    cnt->next = lt->next;
                    lt->next = cnt;
                }
                cnt = last->next;
            }
        }
        return head;
    }
};