/*
 * Lessons: THIS IS GREEDY, INTERVAL SCHEDULING. Also, I learned how to use
 * std::sort here :)
 */


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 //THIS IS INTERVAL SCHEDULING!! HOLY CRAP! I WAS THINKING OF USING DP AT FIRST WHICH IS HOW I FIGURED IT OUT
class Solution {
public:
    struct Comp
    {
        bool operator()(Interval & lhs, Interval & rhs)
        {
            return lhs.end < rhs.end;
        }
    } myObj;
    int eraseOverlapIntervals(vector<Interval>& intervals)
    {   
        if(intervals.size() < 2) return 0;
        std::sort(intervals.begin(), intervals.end(), myObj);
        int num = intervals.size();
        int currEnd = intervals[0].end;
        int count = 1;
        for(int i = 1; i < num; i++)
        {
            if(currEnd <= intervals[i].start)
            {
                count++;
                currEnd = intervals[i].end;
            }
        }
        
        return num - count;    
    }
};
