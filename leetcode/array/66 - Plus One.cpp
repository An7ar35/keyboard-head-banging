class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto v     = std::vector<int>( digits.size() );
        auto it    = v.rbegin();
        auto digit = digits.rbegin();
        int  carry = 1;
        
        while( digit != digits.rend() ) {
            if( carry && *digit == 9 ) {
                *it = 0;
            } else {
                *it   = *digit + carry;
                carry = 0;
            }
            ++digit;
            ++it;
        }
        
        if( carry )
            v.insert( v.begin(), carry );
        
        return v;
    }
}; 
