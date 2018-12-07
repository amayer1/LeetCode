class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size()) return false;
        std::unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        for(int i = 0; i < t.size(); i++)
        {
            if(!freq.count(t[i])) return false;
            freq[t[i]]--;
            if(freq[t[i]] == 0) freq.erase(t[i]);
        }
        return !freq.size();
    }
};
