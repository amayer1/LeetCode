//This one doesn't pass all tests
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
       ListNode* sumHead = new ListNode(0);
       ListNode* sumTrav = sumHead;
       int carry = 0;
       
       while(l1 != NULL && l2 != NULL)
       {
            int sum = l1->val + l2->val + carry;
            carry = 0;
            if(sum > 9 && (l1->next || l2->next))
            {
                sum -= 10;
                carry = 1;
            }
            sumTrav->val = sum;
            l1 = l1->next;
            l2 = l2->next;
            if(l1 || l2)
            {
                sumTrav->next = new ListNode(0);
                sumTrav = sumTrav->next;
            }
       }
       
       if(l1)
       {
            sumTrav->val = l1->val;
            sumTrav->next = l1->next;
       }
       else if(l2)
       {
            sumTrav->val = l2->val;
            sumTrav->next l2->next;
       }

       return sumHead;

    }
};
