class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        std::vector<vector<int>> pascalRows(numRows,std::vector<int>(1,1));
        
        if(numRows < 1) return pascalRows;
        if(numRows == 1) return pascalRows;
        
        for(int i = 1; i < numRows; ++i)
        {
            for(int j = 1; j < pascalRows[i-1].size(); j++)
                pascalRows[i].push_back(pascalRows[i-1][j-1] + pascalRows[i-1][j]);
            pascalRows[i].push_back(1);
        }
        return pascalRows;
    }
};
