class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {  
        std::vector<int> returnArr;
        std::unordered_map<int, int> complimentMap;
           
        for(int i = 0; i < nums.size(); i++)
        {
            if(complimentMap.count(target - nums[i]))
            {
                returnArr.push_back(i);
                returnArr.push_back(complimentMap[target - nums[i]]);

                return returnArr;
             }
             complimentMap[nums[i]] = i;
        }   
    }
};
