class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if( matrix.size() == 0 || matrix.size() == 1 )
            return;
        
        auto rings = matrix.size() / 2; //e.g. 5x5 matrix = 2 'rings' of data to rotate (the middle 1x1 in odd n length matrices is ignored).
        auto n     = matrix.size() - 1;
        
        for( auto r = 0; r < rings; ++r ) {
            //std::cout << "ring: " << r << std::endl;
            for( auto i = r; i < n - r; ++i ) { //top edge of data in the current 'ring'
                
                // For each cells on the top row all equivalent cells in 
                // left/bottom/right edges are moved into each other to complete the rotation
                //
                // We use the formuli $x = y_{curr}$ and $y = n - x_{curr}$ to get 
                // the coordinates of the cell that will rotate into the current (x,y)
                //
                // Note that matrix[] is a row (i.e.: 'y') and matrix[][] is a colum (i.e.: 'x').
                
                int temp = matrix[r][i]; //starting cell of the ring
                //std::cout << "temp = " << temp << std::endl;
                //std::cout << matrix[r][i] << " = " << matrix[n-i][r] << std::endl;
                matrix[r][i]         = matrix[n-i][r];       //left edge   -> top edge
                //std::cout << matrix[n-i][r] << " = " << matrix[n-r][n-i] << std::endl;
                matrix[n-i][r]       = matrix[n-r][n-i];     //bottom edge -> left edge
                //std::cout << matrix[n-r][n-i] << " = " << matrix[n-(n-i)][n-r] << std::endl;
                matrix[n-r][n-i]     = matrix[n-(n-i)][n-r]; //right edge  -> botton edge
                //std::cout << matrix[n-(n-i)][n-r] << " = " << temp << std::endl;
                matrix[n-(n-i)][n-r] = temp;                 //top edge    -> right edge
            }
        }        
    }
};



//FASTER WITH CACHE
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if( matrix.size() == 0 || matrix.size() == 1 )
            return;
        
        auto rings = matrix.size() / 2; //e.g. 5x5 matrix = 2 'rings' of data to rotate (the middle 1x1 in odd n length matrices is ignored).
        auto n     = matrix.size() - 1;
        
        for( auto r = 0; r < rings; ++r ) {
            int nr = n - r; //cache: bottom/right edge boundary for the current 'ring'
            
            for( auto i = r; i < n - r; ++i ) { //top edge of data in the current 'ring'
                
                // For each cells on the top row all equivalent cells in 
                // left/bottom/right edges are moved into each other to complete the rotation
                //
                // We use the formuli $x = y_{curr}$ and $y = n - x_{curr}$ to get 
                // the coordinates of the cell that will rotate into the current (x,y)
                //
                // Note that matrix[] is a row (i.e.: 'y') and matrix[][] is a colum (i.e.: 'x').
                
                int ni = n - i; //cache
                
                int temp       = matrix[r][i];   //starting cell of the ring
                matrix[r][i]   = matrix[ni][r];  //left edge   -> top edge
                matrix[ni][r]  = matrix[nr][ni]; //bottom edge -> left edge
                matrix[nr][ni] = matrix[i][nr];  //right edge  -> botton edge
                matrix[i][nr]  = temp;           //top edge    -> right edge
            }
        }        
    }
};

//4ms, 8.9MB faster than 100% of C++ submission and uses less the 99.70% of memory that the C++ submissions
