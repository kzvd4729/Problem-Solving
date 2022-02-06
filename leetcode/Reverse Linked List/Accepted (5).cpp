/****************************************************************************************
*  @author: kzvd4729                                         created: 04/13/2021 14:15                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 8.5 MB                               
*  problem: https://leetcode.com/problems/reverse-linked-list
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
    ListNode* reverseList(ListNode* head) {
                if(head==NULL)return head;
                vector<ListNode*>v;
        while(head!=NULL)
        {
            v.push_back(head);
            head=head->next;
        }
                reverse(v.begin(),v.end());
                for(int i=0;i<(int)v.size()-1;i++)
        {
            v[i]->next=v[i+1];
        }
        v[(int)v.size()-1]->next=NULL;
                return v[0];
    }
};