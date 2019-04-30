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
    bool isSymmetric(TreeNode* root) {
        if( !root )       
            return true;

        auto curr_level = std::make_unique<std::list<TreeNode*>>();
        auto next_level = std::make_unique<std::list<TreeNode*>>();
        
        next_level->push_back( root->left );
        next_level->push_back( root->right );
        
        while (!next_level->empty()) {
            curr_level.reset( next_level.release() );
            next_level = std::make_unique<std::list<TreeNode*>>();
            
            if( !isLevelSymmetric( *curr_level ) )
                return false;
            
            for( auto node : *curr_level ) {
                if( node ) {
                next_level->push_back( node->left );
                    next_level->push_back( node->right );
                }
            }
        }
        
        return true;        
    }
    
    bool isLevelSymmetric( std::list<TreeNode *> &level ) {
        if( level.size() % 2 > 0 )
            return false;
        
        auto mid     = level.size() / 2;
        auto counter = 0;
        auto fwd     = level.begin();
        auto rev     = level.rbegin();
        
        while( fwd != level.end() && rev != level.rend() && counter < mid ) {
            if( bool(*fwd) ^ bool(*rev) )
                return false;
            if( ( *fwd && *rev ) && ( (*fwd)->val != (*rev)->val ) )
                return false;
            ++fwd;
            ++rev;
            ++counter;
        }
        return true;
    }
    
}; 
