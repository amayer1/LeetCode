/*
 *Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.
 *
 * Wrote notees about this questions in my string journal, but it's very similar
 * to LCS
 */

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int DPMatrix[word2.size()+1][word1.size()+1];
        
        int counter = 0;
        //Initial Conditions
        for(auto & row: DPMatrix[0])        
        {
            row = counter;
            counter++;
        }
        for(int i = 0; i < word2.size()+1; i++)
        {
            DPMatrix[i][0] = i;
        }
        
        for(int i = 1; i < word2.size()+1; i++)
        {
            for(int j = 1; j < word1.size()+1; j++)
            {
                if(word1[j-1] == word2[i-1])
                    DPMatrix[i][j] = DPMatrix[i-1][j-1];      
                else
                    DPMatrix[i][j] = 1 + std::min(DPMatrix[i-1][j],DPMatrix[i][j-1]);
            }
        }
        
        return DPMatrix[word2.size()][word1.size()];
        
    }
};
