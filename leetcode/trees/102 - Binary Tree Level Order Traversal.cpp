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
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto result = std::vector<std::vector<int>>();
        if (root) {
            auto queue = std::deque<TreeNode*>();
            queue.emplace_front(root);
            while (!queue.empty()) {
                size_t items = queue.size();
                result.emplace_back( std::vector<int>() );
                for( int count = 0; count < items; ++count ) {
                    auto current = queue.front();
                    result.back().emplace_back( current->val );
                    queue.pop_front();
                    if( current->left ) queue.push_back( current->left );
                    if( current->right ) queue.push_back( current->right );
                }                
            }
        }
        return result;
    }
}; 
