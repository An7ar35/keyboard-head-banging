class Solution {
  public:
    int reverse(int x) {
        auto s = std::to_string( x );
        std::reverse(
            ( x < 0 ? std::next( s.begin() ) : s.begin() ), s.end()
        );
        auto l = stol( s );

        if( l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max() )
            return 0;
        else
            return static_cast<int>( l );
    }
};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
//Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Reverse Integer.