class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        std::sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){return a[1]<b[1];});
        int endTime = pairs[0][1];
        int res = 1;
        for(auto & each : pairs)
        {
            if(each[0] > endTime)
            {
                res++;
                endTime = each[1];
            }
        }
        return res;
    }
};
