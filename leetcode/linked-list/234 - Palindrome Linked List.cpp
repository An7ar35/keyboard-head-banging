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
    bool isPalindrome(ListNode* head) {
        if( !head ) //size == 0
            return true;
        
        ListNode *mid  = head;
        int       i    = 0;
        int       size = 1;
        
        { //Find mid point in linked list
            ListNode *ptr = head;

            while( ptr && ptr->next ) {
                mid = mid->next;
                ptr = ptr->next->next;
                ++i;
                size += ( ptr ? 2 : 1 );
            }
        }
        
        auto stack = std::stack<ListNode *>();
        
        { //Fill stack with 2nd half of list
            ListNode *ptr = mid;
            
            if( size % 2 > 0 ) //odd number of elements in list so skip middle element
                ptr = ptr->next;
            
            while( ptr ) {
                stack.push( ptr );
                ptr = ptr->next;
            }
        }
        
        ListNode *ptr = head;
        while( !stack.empty() ) {
            if( ptr->val != stack.top()->val )
                return false;
            stack.pop();
            ptr = ptr->next;
        }
        
        return true;
    }
};

//Runtime: 24 ms
//Memory Usage: 13.4 MB
