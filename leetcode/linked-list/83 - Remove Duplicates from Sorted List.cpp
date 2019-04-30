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
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == nullptr )
            return head;
        
        auto current = head;
        while( current != nullptr && current->next != nullptr ) {
            if( current->val == current->next->val ) {
                ListNode * temp = current->next;
                current->next = current->next->next;
                temp->next = nullptr;
                delete temp;
            } else {
                current = current->next;
            }
        }
        
        return head;
    }
}; 
