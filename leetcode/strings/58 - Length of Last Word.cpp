class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t prev_length = 0;
        size_t curr_length = 0;
        
        for( auto c : s ) {
           if( c == ' ' && curr_length > 0 ) {
               prev_length = curr_length;
               curr_length = 0;
           } else if( c != ' ' ) {
               ++curr_length;
           }
        }
        
        return ( curr_length > 0 ? curr_length : prev_length );
    }
}; 
