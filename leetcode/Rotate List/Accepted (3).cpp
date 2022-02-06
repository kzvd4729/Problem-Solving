/****************************************************************************************
*  @author: kzvd4729                                         created: 07/13/2021 17:26                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 11.8 MB                              
*  problem: https://leetcode.com/problems/rotate-list
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL)return head;
                int sz=0;
                ListNode* tmp=head;
        ListNode* tail;
                while(tmp!=NULL)
        {
            sz++;
            tail=tmp;
            tmp=tmp->next;
        }
        k%=sz;
                if(k==0)return head;
                k=sz-k;
                tmp=head;
        for(int i=1;i<k;i++)tmp=tmp->next;
        tail->next=head;
                head=tmp->next;
        tmp->next=NULL;
                return head;
            }
};