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
    void deleteNode(ListNode* node) {
        ListNode *temp = node->next;
        *node = *temp; //copy over dereferenced next node to the node
        delete temp;
    }
};

//Runtime: 16 ms
//Memory Usage: 9.3 MB

