class Solution {
public:
    void reverseString(vector<char>& s) {
        auto mid = s.size() / 2;
        auto fwd = 0;
        auto rev = s.size() - 1;
        while( fwd < mid ) {
            std::swap( s.at( fwd ), s.at( rev ) );
            ++fwd;
            --rev;
        }
    }
}; 
