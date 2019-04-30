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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto a = l1;
        auto b = l2;
        int  carry = 0;
        
        ListNode *head  = nullptr;
        ListNode *digit = nullptr;
        
        do {
            if( !head ) {
                head = add( a, b, carry );
                digit = head;
            } else {
                digit->next = add( a, b, carry );
                digit = digit->next;
            }
            if( a ) a = a->next;
            if( b ) b = b->next;
            
        } while( a || b || carry );
        
        return head;
    }
    
    ListNode* add( ListNode *a, ListNode *b, int &carry ) {
        auto sum = ( a ? a->val : 0 ) + ( b ? b->val : 0 ) + carry;
        if( sum > 9 ) {
            carry = 1;
            return new ListNode( sum % 10 );
        } else {
            carry = 0;
            return new ListNode( sum );
        }
    }
}; 

//28ms, 10.4MB
