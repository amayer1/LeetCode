class Solution {
public:
    int countSubstrings(string s) 
    {
        int strSize = s.size();
        std::vector<std::vector<int>> dp (strSize, std::vector<int>(strSize, 0));
        
        for(int k = 0; k < strSize; k++)
        {
            for(int i = 0, j = k; j < strSize; j++, i++)
            {
                if(i == j) dp[i][j] = 1; 
                else if(s[i] == s[j])
                {
                    if(i == j-1) dp[i][j] = 1;
                    else if(dp[i+1][j-1]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else dp[i][j] = 0;
            }
        }
        int res = 0;
        for(auto & row : dp)
            res = std::accumulate(row.begin(), row.end(), res);
        return res;
    }
};
