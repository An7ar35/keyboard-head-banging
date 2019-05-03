class Solution {
public:
    bool isPalindrome(string s) {        
        s.erase( std::remove_if( s.begin(), s.end(), []( char c ) { return isalpha( c ) == 0 && isdigit( c ) == 0; } ), s.end() );
        
        if( s.empty() )
            return true;
        
        auto half = s.length() / 2;
        for( int fwd = 0, rev = s.length() - 1; fwd <= half; ++fwd, --rev ) {
            if( std::tolower( s.at( fwd ) ) != std::tolower( s.at( rev ) ) )
                return false;
        }
        
        return true;
    }
};

//12ms, 9.4MB
