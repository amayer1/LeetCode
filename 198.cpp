/*
* Easy DP question
*/
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int numLen = nums.size();
        if(!numLen)
            return 0;
        
        
        std::unordered_map<int,int> DP;
        DP[0] = 0;
        DP[1] = nums[0];
        
        for(int i = 2; i <= numLen; i++)
        {
            DP[i] = std::max(DP[i-1], DP[i-2]+nums[i-1]);
        }
        return DP[numLen];
    }
};
