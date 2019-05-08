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
    bool hasCycle(ListNode *head) {
        if( !head || head->next == nullptr ) //0..1 nodes
            return false;
        
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head;
        
        do {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            
            if( fast_ptr ) 
                fast_ptr = fast_ptr->next;
            
            if( fast_ptr == slow_ptr )
                return true;
        } while( fast_ptr );
        
        return false;
    }
}; 

//Runtime: 12 ms
//Memory Usage: 9.8 MB
