class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto total = ( nums.size() * ( nums.size() + 1 ) ) / 2; //triangle number: n(n+1) / 2
        for( auto n : nums )
            total -= n;
        return total;
    }
};

//Runtime: 20 ms
//Memory Usage: 10 MB
