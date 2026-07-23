class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //first use the first row and first col as holders
        //iterate for all rows and cols except for the first row and col
        //then iterate over first row based on matrix[0][0]
        //then lastly iterate over first col based on col0
        int rows = matrix.size();
        int cols = matrix[0].size();
        // vector<int> isRowZero(rows, 0); -> matrix[0][..]
        // vector<int> isColZero(cols, 0); -> matrix[..][0]
        int col0 = 1;
        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                if(matrix[r][c] == 0){
                    if(c == 0) col0 = 0;
                    else matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        for(int r = rows-1; r>0; r--){
            for(int c = cols-1; c>0; c--){
                if(matrix[0][c] == 0 || matrix[r][0] == 0){
                    matrix[r][c] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int c=cols-1; c>=0; c--)
                matrix[0][c] = 0;
        }
        if(col0 == 0){
            for(int r=0; r<rows; r++)
                matrix[r][0] = 0;
        }
    }

};