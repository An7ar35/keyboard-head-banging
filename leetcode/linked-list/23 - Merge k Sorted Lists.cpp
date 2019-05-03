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
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        auto min_heap = std::priority_queue<ListNode*, std::vector<ListNode *>, Comparator>();
        
        for( ListNode *list_head : lists )
            if( list_head )
                min_heap.push( list_head );
            
        while( !min_heap.empty() ) {
            auto temp = min_heap.top();
            min_heap.pop();
            
            if( temp && temp->next ) {
                min_heap.push( temp->next );
                temp->next = nullptr;
            }
            
            if( !head ) { //first!
                head = temp;
                curr = head;
            } else {
                curr->next = temp;
                curr = curr->next;
            }
        }
            
        return head;
    }
    
    struct Comparator {
        bool operator()( ListNode *a, ListNode *b ) {
            return a->val > b->val;
        }
    };
};

//28ms, 11.3MB
