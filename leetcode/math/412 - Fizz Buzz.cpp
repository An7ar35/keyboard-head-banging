class Solution {
public:
    vector<string> fizzBuzz(int n) {
        auto v = std::vector<std::string>();
        for( int i = 1; i <= n; ++i ) {
            bool three = i % 3 == 0;
            bool five  = i % 5 == 0;
            if( three && five )
                v.emplace_back( "FizzBuzz" );
            else if( three )
                v.emplace_back( "Fizz" );
            else if( five )
                v.emplace_back( "Buzz" );
            else 
                v.emplace_back( std::to_string( i ) );
        }
        return v;
    }
}; 
