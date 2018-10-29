/*
 * This solution works, but I think it's inneficient. What is happening is that
 * we have an array for each character in the alphabet and hashes what partition
 * that character is. If we see that character again, then the partition needs
 * to be changed for all character seen beteen the two instances.
 *
 * So for example, say we has a string 'a b c d e f g h a' ..Each letter will
 * get its own partition until the very last. In which case we need to iterate
 * and update all the character's position. A worst case string looks like:
 *
 * 'a b c d e e d c b a;
 *
 * First, 'a' 'b' 'c' 'd' 'e' are given their own parition but once we hit the
 * second 'e', they now share one. Once we hit the second 'd' we need to update
 * the partition from letters d...d and then once we get to c we need to update
 * c..c then b...b then a...a. This could very well be an O(n^2) solution. 
 */

class Solution {
public:
    
    const int ASCII = 97;
    void adjustCharPartitions(string & S, int i, std::vector<int> & charPartition)
    {
        int partition = charPartition[S[i] - ASCII];
        char c = S[i];
        i--;
        while(S[i] != c)
        {
            charPartition[S[i] - ASCII] = partition;
            i--;
        }
    }
    void adjustPartitionSizes(std::vector<int> & partitionSizes, int partition)
    {
       int sum = 0;
       int currPartition = partitionSizes.size() - 1;
       while(currPartition > partition - 1)
       {
           sum += partitionSizes[currPartition];
           partitionSizes.pop_back();
           currPartition--;
       }
       partitionSizes[partition-1] += sum+1;
    }
    vector<int> partitionLabels(string S) 
    {
        std::vector<int> charPartition (26,0);
        std::vector<int> partitionSizes;
        int currPartition = 1;
        
        for(int i = 0; i < S.size(); i++)
        {
            int index = S[i] - ASCII;
            if(charPartition[index])
            {
                int partition = charPartition[index];
                adjustCharPartitions(S,i,charPartition);
                adjustPartitionSizes(partitionSizes, partition);   
                currPartition = partition + 1;
            }
            else
            {
                charPartition[index] = currPartition;
                partitionSizes.push_back(1);
                currPartition++;
            }
        }
        
        return partitionSizes;
    }
};
