/*
 * Made improvements. 
 * Lessons: To get number of rows in a 2D vector, myVector, just do
 * myVector.size(), to get number of columns, do myVector[0].size()
 *
 * Lesson: This approach only uses a single nested for loop to get the minimums
 * and maximums for each vertical and horizontal skyline. We only need to visit
 * each element once to get that information. 
 */
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        std::vector<int> vertSkyline (numCols,0);
        std::vector<int> horizSkyline (numRows,0);
        
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < numCols; j++)
            {
                vertSkyline[j]  = std::max(vertSkyline[j],  grid[i][j]);
                horizSkyline[i] = std::max(horizSkyline[i], grid[i][j]);
            }
        }
        
        int sum = 0;
        for(int i = 0; i < numRows; i++)
        {    
            for(int j = 0; j < grid[0].size(); j++)
            {
                sum += std::min(vertSkyline[j],horizSkyline[i]) - grid[i][j]; 
            }
        }       
        return sum;
    }
};
