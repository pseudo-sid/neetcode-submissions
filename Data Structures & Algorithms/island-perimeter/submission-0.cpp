class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        vector<int> dirs = {1, 0, -1, 0, 1};

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int new_i = i + dirs[k], new_j = j + dirs[k+1];
                        perimeter += (new_i < 0 or new_i >= grid.size() or new_j < 0 or new_j >= grid[0].size() or grid[new_i][new_j] != 1);
                    }
                }

        return perimeter;
    }
};