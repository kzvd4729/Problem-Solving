/****************************************************************************************
*  @author: kzvd4729                                         created: 03/04/2021 21:12                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 16 ms                                           memory_used: 11.9 MB                              
*  problem: https://leetcode.com/problems/reverse-nodes-in-k-group
****************************************************************************************/
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k)
  {
    vector<ListNode*>v;
    while(head!=NULL)
    {
      v.push_back(head);
      head=head->next;
    }
    int n=v.size();int r=n%k;
    ListNode *ret=NULL;
    if(r)ret=v[n-r];
    for(int i=n-r-k;i>=0;i-=k)
    {
      ListNode *now=ret;
      for(int j=i;j<i+k;j++)
      {
        v[j]->next=now;
        now=v[j];
      }
      ret=now;
    }
    return ret;
  }
};