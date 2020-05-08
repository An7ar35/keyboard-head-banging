class Solution {
  public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false;

        auto v = std::vector<int>();

        do {
            auto i = x % 10;
            x -= i;
            x /= 10;
            v.emplace_back( i );
        } while( x > 0 );

        auto half   = v.size() / 2;
        auto fwd_it = v.begin();
        auto bck_it = std::prev( v.end() );

        if( v.size() % 2 == 0 ) { //even
            for( ; fwd_it != std::next( fwd_it, half ) && fwd_it != v.end(); ++fwd_it, --bck_it ) {
                if( *fwd_it != *bck_it )
                    return false;
            }

        } else { //odd
            for( ; fwd_it != bck_it && fwd_it != v.end(); ++fwd_it, --bck_it ) {
                if( *fwd_it != *bck_it )
                    return false;
            }
        }

        return true;
    }
};