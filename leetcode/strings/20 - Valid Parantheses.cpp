class Solution {
public:
    bool isValid(string s) {
        auto open = std::stack<char>();
        
        for( auto c : s ) {
            switch( c ) {
                case '(':
                case '{': [[fallthrough]];
                case '[': {
                    open.push( c );
                } break;
                    
                case ')': {
                    if( !open.empty() && open.top() == '(' ) {
                        open.pop();
                    } else {
                        return false;
                    }
                } break;
                    
                case '}': {
                    if( !open.empty() && open.top() == '{' ) {
                        open.pop();
                    } else {
                        return false;
                    }
                } break;
                    
                case ']': {
                    if( !open.empty() && open.top() == '[' ) {
                        open.pop();
                    } else {
                        return false;
                    }
                } break;
                    
                default: { //invalid char
                    return false;
                }
            }
        }
        
        return open.empty();
    }
}; 
