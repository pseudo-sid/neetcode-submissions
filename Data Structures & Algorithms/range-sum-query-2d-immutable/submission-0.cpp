class NumMatrix {
/*
[[[
[3, 0, 1, 4, 2], 
[5, 6, 3, 2, 1], 
[1, 2, 0, 1, 5], 
[4, 1, 0, 1, 7], 
[1, 0, 3, 0, 5]]]

cumSum[i][j] += cumSum[i][j-1] + cumSum[i-1][j] - cumSum[i-1][j-1]
cumSum:
[[[
[3, 3, 4, 8, 10], 
[8, 14,18, 2, 1], 
[1, 2, 0, 1, 5], 
[4, 1, 0, 1, 7], 
[1, 0, 3, 0, 5]]]
*/
vector<vector<int>> grid;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->grid = matrix;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++){
                if(i > 0)
                    grid[i][j] += grid[i-1][j];
                if(j > 0)
                    grid[i][j] += grid[i][j-1];
                if(i > 0 and j > 0)
                    grid[i][j] -= grid[i-1][j-1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        vector<int> topLeft = {min(row1, row2), min(col1, col2)}, 
        bottomRight = {max(row1, row2), max(col1, col2)};

        int ans = grid[bottomRight[0]][bottomRight[1]];
        if(topLeft[0] > 0)
            ans -= grid[topLeft[0]-1][bottomRight[1]];
        if(topLeft[1] > 0)
            ans -= grid[bottomRight[0]][topLeft[1]-1];
        if(topLeft[0] > 0 and topLeft[1] > 0)
            ans += grid[topLeft[0]-1][topLeft[1]-1];

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */