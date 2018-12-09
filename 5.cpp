class Solution {
public:
    string longestPalindrome(string s) 
    {  
        if(s == "") return s;
        std::vector<std::vector<int>> dp (s.size(), std::vector<int> (s.size(), 0));
        std::pair<int, int> maxIndex = make_pair(0, 0);
        for(int k = 0; k < s.size(); k++)
        {
            for(int i = 0, j = k; j < s.size(); i++, j++)
            {
                if(k == 0) dp[i][j] = 1;
                else if(s[i] != s[j]) dp[i][j] = 0;
                else if(s[i] == s[j] && i+1 == j) dp[i][j] = 2;
                else dp[i][j] = (dp[i+1][j-1] >= 1) ? dp[i+1][j-1] + 2 : 0;
                if(dp[i][j] > dp[maxIndex.first][maxIndex.second]) maxIndex = make_pair(i, j);
            }
        }
        std::cout << maxIndex.first << maxIndex.second << dp[maxIndex.first][maxIndex.second] << std::endl;
        return s.substr(maxIndex.second - dp[maxIndex.first][maxIndex.second] + 1, dp[maxIndex.first][maxIndex.second]);
    }
};
