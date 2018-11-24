class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        std::vector<int> res (T.size(), 0);
        std::stack<std::pair<int, int>> myStack;
        myStack.push(make_pair(T[0], 0));
        
        for(int i = 1; i < T.size(); i++)
        {
            while(myStack.size() && T[i] > myStack.top().first)
            {
                    res[myStack.top().second] = i - myStack.top().second;
                    myStack.pop();
            }
                myStack.push(make_pair(T[i], i));
        }
        return res;
    }
};
