/****************************************************************************************
*  @author: kzvd4729                                         created: 03/04/2021 17:40                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 48 ms                                           memory_used: 14.1 MB                              
*  problem: https://leetcode.com/problems/merge-k-sorted-lists
****************************************************************************************/
class Solution
{
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) 
  {
    vector<pair<int,ListNode*> >v;
    for(auto x:lists)
    {
      ListNode *head=x;
      while(head!=NULL)
      {
        v.push_back({head->val,head});
        head=head->next;
      }
    }
    sort(v.begin(),v.end());
    ListNode *ret=NULL;
    for(int i=v.size()-1;i>=0;i--)
    {
      v[i].second->next=ret;
      ret=v[i].second;
    }
    return ret;
  }
};