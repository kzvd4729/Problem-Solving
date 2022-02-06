/****************************************************************************************
*  @author: kzvd4729                                         created: 04/13/2021 13:18                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 24 ms                                           memory_used: 11.1 MB                              
*  problem: https://leetcode.com/problems/linked-list-cycle
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
    bool hasCycle(ListNode *head) {
                set<ListNode*>st;
                while(head!=NULL)
        {
            st.insert(head);
            head=head->next;
                        if(st.find(head)!=st.end())return true;
        }
        return false;
    }
};