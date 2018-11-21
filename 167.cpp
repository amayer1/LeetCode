class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        std::vector<int> res;
        int left  = 0;
        int right = numbers.size() - 1;
        for(int left  = 0, right = numbers.size() - 1;;)
        {
            int sum = numbers[left] + numbers[right];
            if(sum == target)
            {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            if(sum < target) 
                left++;
            else 
                right--;
        }
    }
};
