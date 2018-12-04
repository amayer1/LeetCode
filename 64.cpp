class Solution {
public:
    int dynProg(vector<vector<int>>& grid, int row, int col)
    {
        if(row == 0 && col == 0) return grid[row][col];
        int top = std::numeric_limits<int>::max();
        int left = top;
        if(row > 0) top  =  dynProg(grid, row - 1, col);
        if(col > 0) left = dynProg(grid, row, col - 1);
        return std::min(top, left) + grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        return dynProg(grid, grid.size() - 1, grid[0].size() -1);    
    }
};
