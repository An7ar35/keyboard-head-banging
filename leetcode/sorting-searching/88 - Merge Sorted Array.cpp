class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for( int from = 0, to = m; from < nums2.size(); ++from, ++to )
            nums1.at( to ) = nums2.at( from );
        
        std::sort( nums1.begin(), nums1.end() );            
    }
};

//Runtime: 4 ms
//Memory Usage: 8.8 MB
