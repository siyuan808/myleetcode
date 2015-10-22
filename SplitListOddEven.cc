#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

struct ListNode  {
    int val;
    ListNode *next;
    ListNode(int v) : val(v) {
        next = NULL;
    };
};

vector<ListNode*> split(ListNode* head) {
    //split list into two, odd and even
    ListNode *even, *evenTail = NULL;
    ListNode *dummy, *pre;
    dummy = pre = new ListNode(0);
    pre->next = head;
    while(pre->next) {
        if(pre->next->val % 2 == 0) {
            if(evenTail == NULL) {
                even = evenTail = pre->next;
            } else {
                evenTail->next = pre->next;
                evenTail = evenTail->next;
            }
            pre->next = pre->next->next;
            evenTail->next = NULL;
        } else {
            pre = pre->next;
        }
    }
    ListNode *odd = dummy->next;
    delete dummy;
    return vector<ListNode*>{odd,even};
}

void printList(ListNode *head) {
    while(head) {
        cout <<head->val<<" ";
        head = head->next;
    }
    cout <<endl;
}

int main() {
    ListNode *head = NULL;
    ListNode *tail = head;
    vector<int> arr {1,2,3,4};
    for(int i = 0; i < arr.size(); i++) {
        int val  = arr[i];
        if(head == NULL) {
            head = tail = new ListNode(val);
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
    //printList(head);
    vector<ListNode*> twoLists = split(head);
    printList(twoLists[0]);
    printList(twoLists[1]);
}
