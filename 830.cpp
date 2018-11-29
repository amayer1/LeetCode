class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) 
    {
        std::vector<std::vector<int>> res;
        for(int i = 0; i < S.size();)
        {
            int j = i;
            while(S[j] == S[i])
                j++;
            if(j-i > 2)
                res.push_back({i,j-1});
            i = j;
        }
        return res;
    }
};
