/****************************************************************************************
*  @author: kzvd4729                                         created: 03/04/2021 17:26                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 240 ms                                          memory_used: 13.5 MB                              
*  problem: https://leetcode.com/problems/merge-k-sorted-lists
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e4,inf=1e9,mod=1e9+7;
ListNode *merge(ListNode *head,ListNode *x)
{
  if(head==NULL)return x;
  if(x==NULL)return head;
  ListNode *ret;
  if(head->val<x->val)
  {
    ret=head;
    ret->next=merge(head->next,x);
  }
  else
  {
    ret=x;
    ret->next=merge(head,x->next);
  }
  return ret;
}
class Solution
{
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) 
  {
    ListNode *head=NULL;
    if((int)lists.size()==0)return head;
    for(int i=0;i<(int)lists.size();i++)
      head=merge(head,lists[i]);
    return head;
  }
};