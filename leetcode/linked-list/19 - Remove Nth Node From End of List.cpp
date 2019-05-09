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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( !head )
            return nullptr;
        if( n < 1 )
            return head;
        
        ListNode *front = head;
        ListNode *curr  = head;
        ListNode *fwd   = head;
        int       size  = 1; //start at 'head'
        
        for( int interval = 0; fwd->next && interval < n; ++interval, ++size )
            fwd = fwd->next;
        
        while( fwd->next ) {
            curr = curr->next;
            fwd  = fwd->next;
            ++size;
        }
        
        if( size != n ) {
            ListNode *to_remove = curr->next;
            curr->next = curr->next->next;
            to_remove->next = nullptr;
            delete to_remove;
        } else { //remove front
            ListNode *to_remove = front;
            front = front->next;
            to_remove->next = nullptr;
            delete to_remove;
        }
        
        return front;
    }
};

//Runtime: 4 ms
//Memory Usage: 8.6 MB
