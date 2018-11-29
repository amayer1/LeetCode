class Solution {
public:
    
    void backtrack(std::vector<std::vector<int>> & res, int k, int n, std::vector<int> & curr, int currSum, int start)
    {
        if(currSum == n && curr.size() == k)
            res.push_back(curr);
        else if(currSum < n && curr.size() < k)
        {
            for(int i = start; i < 10; i++)
            {
                if(currSum + i > n) break;
                currSum += i;
                curr.push_back(i);
                backtrack(res, k, n, curr, currSum, i+1);
                curr.pop_back();
                currSum -= i;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        
        backtrack(res, k, n, curr, 0, 1);
        
        return res;
    }
};
