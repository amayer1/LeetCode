class Solution {
public:
    int minAddToMakeValid(string S) 
    {
        int balance = 0; 
        int moreParen = 0;
        
        for(auto & c : S)
        {
            if(c == '(')
            {
               balance++;
            }
            else
            {
                if(balance == 0) 
                    moreParen++;
                else
                    balance--;
            }
            
        }
        return moreParen + balance;
    }
};

/*
 * The logic behind this one is interesting. Right paren subtracts one and left
 * paren adds one. If the balance is 0 and we encounter a right paren, nothing
 * later in the string will be able to fix that. We'll always need to add one
 * parenthesis to fix that. It's a sunk cost. We don't change the balance
 * because we just treat everything after that right paren with a fresh slate.
 *
 */
