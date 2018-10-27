class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        std::vector<int> vertSkyline;
        std::vector<int> horizSkyline;
        int numRows = 0;
        
        for(const auto & row : grid)
        {
            horizSkyline.push_back(*std::max_element(row.begin(), row.end()));
            numRows++;
        }
        
        for(int i = 0; i < grid[0].size(); i++)
        {
            int max = 0;
            for(int j = 0; j < numRows; j++)
            {
                if (grid[j][i] > max)
                    max = grid[j][i];
            }
            vertSkyline.push_back(max);
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
