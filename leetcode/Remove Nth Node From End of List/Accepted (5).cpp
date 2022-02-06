/****************************************************************************************
*  @author: kzvd4729                                         created: 07/13/2021 15:23                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 10.7 MB                              
*  problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list
****************************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int sz=0;
        ListNode* tmp=head;
        while(tmp!=NULL)
        {
            sz++;
            tmp=tmp->next;
        }
                n=sz-n+1;
        if(n==1)return head->next;
                tmp=head;
        for(int i=3;i<=n;i++)tmp=tmp->next;
                ListNode* del=tmp->next;
        tmp->next=(tmp->next)->next;
                delete del;
                return head;
    }
};