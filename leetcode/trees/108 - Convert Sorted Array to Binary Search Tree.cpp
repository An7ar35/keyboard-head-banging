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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if( nums.empty() )
            return nullptr;
        if( nums.size() == 1 ) {
            return new TreeNode( nums.front() );
        }
        
        //Split the nums into left/right branches
        size_t half = nums.size() / 2;
        TreeNode *root = new TreeNode( nums.at( half ) );
        
        auto left  = std::vector<int>( nums.begin(), nums.begin() + half );
        auto right = std::vector<int>( nums.begin() + ++half, nums.end() );
        
        root->left  = sortedArrayToBST( left );
        root->right = sortedArrayToBST( right );
        
        return root;
    }
}; 
