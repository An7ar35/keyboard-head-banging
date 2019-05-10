/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if( !head )
            return nullptr;
        
        ListNode *front = head;
        ListNode *ptr   = front->next;
        
        while( ptr ) {
            ListNode *next = ptr->next;
            ptr->next  = front;
            head->next = next;
            front = ptr;
            ptr   = next;
        }
        return front;
    }
};

//Runtime: 4 ms
//Memory Usage: 9.4 MB
