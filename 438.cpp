/*
 * Lessons: ANAGRAM PROBLEMS THINK CHARACTER FREQUENCY! 
 * At first I tried doing this with creating an unordered_map and getting
 * frequency of 'p'. Then I hashed that and would get frequencies of S and see
 * if if were in the hash table. Problem is that C++ doesn't know how to hash an
 * unordered_map. Then I tried turning the unordered_map into a string and doing
 * that for S as well. That worked but it was not fast. Then I learned that you
 * can just compare vectors! So I just made a frequency vector and compared!
 */
class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) 
    {
        std::vector<int> res;
        std::vector<int> patternFreq (26,0);
        std::vector<int> stringFreq (26,0);
            
        for(char c : p)
            patternFreq[c - 'a']++; 
        
        for(int  i = 0; i < p.size() - 1; i++)
            stringFreq[s[i]-'a']++;
      
        for(int i = 0, j = p.size() - 1; j < s.size(); i++, j++)
        {
            stringFreq[s[j] -'a']++;
            if(stringFreq == patternFreq)
                res.push_back(i);
            stringFreq[s[i]-'a']--;
        }
        
        return res;
        
    }  
};
