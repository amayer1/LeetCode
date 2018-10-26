class Solution {
public:
    int reverse(int x) 
    {
        long num = 0;
        while(x)
        {
            num = num*10 + x%10;
            x /= 10;
        }
        if(num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        {
            return 0;
        }
        return num;
    }
};

/*
 *Lessons Learned
 *
 * Can use std::numeric_limits to get MAX/MIN of a data type
 * My first attempt was to use a stack, push all the digits one by one, and then
 * reverse by popping. But that was uneccesary. In a single loop, you can
 * deconstruct the 'x' and build up the reverse in 'num'
 *
 *
*/
