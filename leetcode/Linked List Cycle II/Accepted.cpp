/****************************************************************************************
*  @author: kzvd4729                                         created: 04/13/2021 13:22                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 9.5 MB                               
*  problem: https://leetcode.com/problems/linked-list-cycle-ii
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
    ListNode *detectCycle(ListNode *head) {
                unordered_set<ListNode*>st;
                while(head!=NULL)
        {
            st.insert(head);
            head=head->next;
                        if(st.find(head)!=st.end())return head;
        }
        return NULL;
            }
};