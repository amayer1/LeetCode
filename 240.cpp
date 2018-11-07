/*
 * This problem is really important to understand. Check notes. This type of
 * search is called saddleback search
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int len   = matrix.size();
        if(!len) return false; //if input is [[]]
        int width = matrix[0].size();
        
        int row  = len - 1;
        int col = 0;
        
        while(row >= 0 && col < width)
        {
            int num = matrix[row][col];
            
            if(num == target) return true;
            
            (target > num) ? (col++) : (row--);
        }
        
        return false;
    }
};
