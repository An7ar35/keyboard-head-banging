class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i1 = 0, i2 = 0;
        
        while( i1 < nums.size() && i2 < nums.size() ) {
            if( nums.at( i1 ) == 0 ) {
                if( i2 < i1 ) 
                    i2 = i1;
                
                while( i2 < nums.size() && nums.at( i2 ) == 0 )
                    ++i2;
                
                if( i2 < nums.size() )
                    std::swap( nums.at( i1 ), nums.at( i2 ) );
            }
            ++i1;
        }
    }
}; 

//16 ms, 9.7 MB
