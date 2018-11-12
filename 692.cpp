/*
 * Lessons: I wrote notes on this question. Check marble notebook
 *
 */
class Solution {
public:
    
    struct comp
    {
        
        bool operator()(pair<string,int> lhs, pair<string,int> rhs)
        {
            if(lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first))
                return true;
            return false;    
        }
        
  
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {      
           //Top K elements means PRIORITY QUEUE
            priority_queue<pair<string, int>, vector<pair<string,int>>, comp> pq;
            std::unordered_map<std::string, int> map;
        
            for(std::string & str : words)
                map[str]++;
            for(auto & each : map)
            {   
                if(pq.size() < k)
                    pq.push(make_pair(each.first, each.second));
                else if(pq.top().second < each.second || (pq.top().second == each.second && pq.top().first > each.first))
                {
                    pq.pop();
                    pq.push(make_pair(each.first, each.second));
                }
            }
            
            std::vector<std::string> res;
            while(pq.size())
            {
                res.push_back(pq.top().first);
                pq.pop();
            }
            reverse(res.begin(), res.end());
            return res; 
    }
};
