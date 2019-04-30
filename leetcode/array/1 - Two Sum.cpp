class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto map = std::unordered_map<int, int>();
        for( auto i = 0; i < nums.size(); ++i ) {
            auto complement = target - nums.at( i );
            if( map.find( complement ) != map.end() ) {
                return std::vector<int>( { map.at( complement ), i } );
            } else {
                map.emplace( nums.at( i ), i );
            }
        }
        return std::vector<int>();
    }
}; 
