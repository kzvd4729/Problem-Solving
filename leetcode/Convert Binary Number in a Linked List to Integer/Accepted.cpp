/****************************************************************************************
*  @author: kzvd4729                                         created: 12/20/2019 22:33                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 8.4 MB                               
*  problem: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
****************************************************************************************/
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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=NULL)
        {
            ans=ans*2+head->val;
            head=head->next;
        }
        return ans;
    }
};