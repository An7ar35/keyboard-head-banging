class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if( strs.empty() ) {
            return {};
        }
        
        auto deque  = std::deque<char>( strs.front().begin(), strs.front().end() );
        auto str_it = std::next( strs.begin() );
        
        while( str_it != strs.end() ) {
            auto deque_it = deque.begin();
            
            for( auto c : *str_it ) {
                if( deque_it == deque.end() ) {
                   break;
                }
                
                if( c != *deque_it ) {
                    break;
                }
                
                ++deque_it;
            }
            
            if( deque_it != deque.end() ) {
                deque.erase( deque_it, deque.end() );
            }
            
            ++str_it;
        }
        
        return std::string( deque.begin(), deque.end() );
    }
}; 
