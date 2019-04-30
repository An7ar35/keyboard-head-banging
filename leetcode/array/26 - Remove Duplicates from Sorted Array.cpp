class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for( auto it = nums.begin(); it != nums.end(); ) {
            auto next = std::next( it );
            if( next != nums.end() && *it == *next ) {
                it = nums.erase( it );
            } else {
                ++it;
            }
        }
        return nums.size();
    }
}; 
