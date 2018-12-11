class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        std::vector<int>::reverse_iterator rit;
        for(rit = digits.rbegin(); rit != digits.rend(); rit++)
        {
            if(*rit != 9)
            {
                *rit = *rit + 1;
                 return digits;
            }
            *rit  = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
