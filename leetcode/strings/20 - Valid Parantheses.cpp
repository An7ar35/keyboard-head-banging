class Solution {
public:
    bool isValid(string s) {
        auto open = std::stack<char>();
        
        for( auto c : s ) {
            switch( c ) {
                case '(': { open.push( ')' ); } break;
                case '{': { open.push( '}' ); } break;
                case '[': { open.push( ']' ); } break;
                    
                case ')':
                case '}': [[fallthrough]];
                case ']': {
                    if( !open.empty() && open.top() == c ) {
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

//0ms
