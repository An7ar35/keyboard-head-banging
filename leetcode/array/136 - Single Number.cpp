class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if( nums.size() % 2 == 0 )
            throw std::invalid_argument( "There cannot be a single unique element in the array." );
            
        std::sort( nums.begin(), nums.end() );
        auto curr = nums.begin();
        auto next = std::next( curr );
        while( curr != nums.end() ) {
            if( next == nums.end() ) { //last element is the unique int
                return *curr;
            } 
            
            if( *curr != *next ) { //a,b,b
                return *curr;
            }
            
            curr = std::next( curr, 2 );
            next = std::next( next, 2 );
        }
        
        throw std::invalid_argument( "Array has no unique element." );
    }
}; 
