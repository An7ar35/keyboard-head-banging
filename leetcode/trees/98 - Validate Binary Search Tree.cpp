/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if( root )
            return ( isValid( root->left, nullptr, root ) && isValid( root->right, root, nullptr ) );
        else 
            return true;
    }
    
private:
    bool isValid( TreeNode *root, TreeNode* min_node, TreeNode *max_node ) {
        if( !root )
            return true;
        if( ( min_node && root->val <= min_node->val ) || ( max_node && root->val >= max_node->val ) )
            return false;
        else 
            return ( isValid( root->left, min_node, root ) && isValid( root->right, root, max_node ) );
    }
}; 
