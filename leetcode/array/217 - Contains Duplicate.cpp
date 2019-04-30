class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort( nums.begin(), nums.end() );
        for( auto it = nums.begin(); it != nums.end(); ++it ) {
            auto next = std::next( it );
            if( next != nums.end() && *it == *next )
                return true;
        }
        return false;
    }
}; 
