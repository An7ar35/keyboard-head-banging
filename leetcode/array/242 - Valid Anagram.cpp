class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() )
            return false;
        
        auto map = std::unordered_map<char, int>();
        
        for( auto c : s ) {
            if( map.find( c ) == map.end() )
                map.emplace( c, 1 );
            else
                map.at( c )++;
        }
        
        for( auto c : t ) {
            if( map.find( c ) == map.end() )
                return false;
            if( map.at( c ) > 1 )
                map.at( c )--;
            else
                map.erase( c );
        }
        
        return map.empty();
    }
};

//Runtime: 20 ms
//Memory Usage: 9.7 MB
