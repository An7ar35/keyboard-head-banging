class Solution {
public:
    int romanToInt(string s) {
        static const auto VALUE_MAP = std::unordered_map<char, int>( {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 },
        } );
        
        try {
            int sum     = 0;
            int sub_sum = 0;
            
            for( auto it = s.rbegin(); it != s.rend(); ++it ) {
                const auto char_value = VALUE_MAP.at( *it );
                
                if( char_value >= sub_sum ) {
                    sum    += sub_sum;
                    sub_sum = char_value;
                    
                } else { //prefix
                    sub_sum -= char_value;
                }
            }
            
            return ( sum+= sub_sum );
            
        } catch( const std::out_of_range &e ) {
            return 0;
        }
    }
}; 
