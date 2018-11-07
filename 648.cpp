/*
 * I took notes on this question because this question is a good example of
 * using a trie
 */

class Solution {
public:
    int nextWord(int i, string & sentence)
    {
        while(sentence[i] != ' ' && i < sentence.size())
            i++;
        return i;
    }
    string replaceWords(vector<string>& dict, string sentence) 
    {
        //dict the dictionary
        
        std::unordered_set<std::string> dictMap;
        int high = -1;
        int low = 10000;
        for(auto & str : dict)
        {
            dictMap.insert(str);
            int size = str.size();
            if(size > high)
                high = size;
            if(size < low)
                low = size;
        }
        
        for(int i = 0; i < sentence.size(); i++)
        {
            int sizeOfWord = nextWord(i, sentence) - i;
            for(int j = low; j <= high && j < sizeOfWord; j++)
            {
                if(dictMap.count(sentence.substr(i, j)))
                {
                    std::cout << sentence.substr(i, j) << endl;
                    std::cout << sentence.substr(i, sizeOfWord) << endl;
                    sentence.replace(i, sizeOfWord, sentence.substr(i, j));
                    
                   
                    for(auto c : sentence)
                        cout << c;
                  
                    
                    
                    sizeOfWord = j;
                    break;
                }
                    
            }
            
            i += sizeOfWord;
        }
        return sentence;
    }
};
