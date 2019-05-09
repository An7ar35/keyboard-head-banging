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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( !l1 && !l2 )
            return nullptr;
        if( l1 && !l2 )
            return l1;
        if( !l1 && l2 )
            return l2;
        
        auto removeFront = []( ListNode **list ) { 
            ListNode *front = *list;
            *list = (*list)->next;
            front->next = nullptr;
            return front;
        };
        
        ListNode *merge_head = nullptr;
        ListNode *merge_back = nullptr;
        
        merge_head = removeFront( ( l1 && l2 && l1->val < l2->val ) ? &l1 : &l2  );
        merge_back = merge_head;
        
        while( l1 && l2 ) {
            if( l1->val < l2->val ) {
                merge_back->next = removeFront( &l1 );
                merge_back = merge_back->next;
            } else { //>=
                merge_back->next = removeFront( &l2 );
                merge_back = merge_back->next;
            }
        }
        
        while( l1 ) {
            merge_back->next = removeFront( &l1 );
            merge_back = merge_back->next;
        }
        
        while( l2 ) {
            merge_back->next = removeFront( &l2 );
            merge_back = merge_back->next;
        }
        
        return merge_head;
    }
}; 

//Runtime: 4 ms
//Memory Usage: 9 MB
