/****************************************************************************************
*  @author: kzvd4729                                         created: 03/04/2021 17:39                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 24 ms                                           memory_used: 14 MB                                
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