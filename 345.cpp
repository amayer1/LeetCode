class Solution {
public:
    string reverseVowels(string s) 
    {

        std::stack <int> vowels;
        std::unordered_set <char> allVowels = {'a','e','i','o','u', 'A','E','I','O','U'};
        
        for(auto & c : s)
        {
            if(allVowels.count(c))
                vowels.push(c);
        }
        
        if(!vowels.size())
            return s;
        
        for(auto & c : s)
        {
            if(allVowels.count(c))
            {
                c = vowels.top();
                vowels.pop();
            }
        }
        
        return s;
    }
};
