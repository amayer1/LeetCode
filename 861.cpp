/*
 * Once you knew the trick to this one it was pretty easy. Detailed this
 * question with the trick in the notes
 *
 * There's a better solution using bitwise operators, but I don't understand
 * it/Not good with bitwise operators YET
 */
class Solution {
public:
    void colZeroOneCount(vector<vector<int>>& A, std::vector<int>  & indeciesWithZero, std::vector<int> & indeciesWithOne, int col)
    {
        indeciesWithZero.clear();
        indeciesWithOne.clear();
        
        for(int i = 0; i < A.size(); i++)
        {
            (A[i][col] == 1) ? indeciesWithOne.push_back(i) : indeciesWithZero.push_back(i);
        }
    }
    void flipRows(vector<vector<int>>& A, std::vector<int>  & indecies)
    {
        for(int & index : indecies)
        {
            for(int i = 0; i < A[index].size(); i++)
                (A[index][i] == 1) ? A[index][i] = 0 : A[index][i] = 1;
        }
    }
    void flipCol(vector<vector<int>>& A, int col)
    {
        for(auto & row : A)
            (row[col] == 1) ? row[col] = 0 : row[col] = 1;
    }
    int sumRow(std::vector<int> & row)
    {
        int sum = 0;
        int rowSize = row.size();
        for(int i = 0; i < rowSize; i++)
        {   
            sum += (std::pow(2,rowSize - 1 - i) * row[i]);  
        }

        return sum;
    }
    int matrixScore(vector<vector<int>>& A) 
    {
        std::vector<int> indeciesWithZero;
        std::vector<int> indeciesWithOne;
        
        colZeroOneCount(A, indeciesWithZero, indeciesWithOne,0);
        flipRows(A, indeciesWithZero);
        
        for(int i = 1; i < A[0].size(); i++)
        {
            colZeroOneCount(A, indeciesWithZero, indeciesWithOne, i);
            if (indeciesWithZero.size() > indeciesWithOne.size()) { flipCol(A, i); }
        }
        int sum  = 0;
        for(auto & row : A)
            sum += sumRow(row);
        
        return sum;
    }
};
