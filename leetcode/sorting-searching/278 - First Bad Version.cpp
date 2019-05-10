// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        auto low  = 1;
        auto high = n;
        
        while( low < high ) {
            int mid = low + ( high - low ) / 2;
            // std::cout << "window: " << low << " -> " << high << "  mid=" << mid << std::endl;            
            if ( !isBadVersion( mid ) ) 
                low = mid + 1; //'mid' still ok so bad ver. must be above therefore mid+1 becomes the new 'low'
            else 
                high = mid; //'mid' is a bad ver. so 'high' becomes 'mid' so as to allow searching for the versions < than that.
        }
        
        return low;
    }
};

//Runtime: 0 ms
//Memory Usage: 8.3 MB
