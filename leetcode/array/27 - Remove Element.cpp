class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it1 = nums.begin();
        auto it2 = it1;
        
        while( it2 != nums.end() ) {
            if( *it2 != val ) {
                *it1 = *it2;
                ++it1;
            }
            
            ++it2;
        }
        
        return std::distance( nums.begin(), it1 );
    }
};
