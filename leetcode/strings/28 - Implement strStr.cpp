class Solution {
public:
    int strStr(string haystack, string needle) {
        if( needle.empty() )
            return 0;
        if( needle.length() > haystack.length() )
            return -1;

        for( int index = 0; index < haystack.length() - needle.length() + 1; ++index ) {
            if( haystack.at( index ) == needle.at( 0 ) ) {
                int hi = index; //haystack index
                int ni = 0;  //needle index
                while( hi < haystack.length() && ni < needle.length() &&
                       haystack.at( hi ) == needle.at( ni ) ) {
                    ++hi;
                    ++ni;
                }

                if( ni >= needle.length() )
                    return index;
            }
        }

        return -1;
    }
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Implement strStr().
//Memory Usage: 9.2 MB, less than 98.64% of C++ online submissions for Implement strStr().
