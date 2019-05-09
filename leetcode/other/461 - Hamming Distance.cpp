class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        return __builtin_popcount( x ); //Bwahahaahahahah!!!
    }
};

//Runtime: 4 ms
//Memory Usage: 8.3 MB
