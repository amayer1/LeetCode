class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        std::stack<int> nums;
        int res = 0;
        for(std::string & c : ops)
        {
            if(c == "C") 
            {
                res -= nums.top();
                nums.pop();
    
            }
            else if(c == "+")
            {
                int one = nums.top();
                nums.pop();
                int two = nums.top();
                nums.push(one);
                nums.push(one + two);
                res += one + two;
            }
            else if(c == "D")
            {
                int i = nums.top();
                nums.push(2 * i);
                res += 2*i;
            }
            else
            {
                int i = stoi(c);
                nums.push(i);
                res += i;
            }
            std::cout << res << std::endl;
        }
        return res;
    }
};
