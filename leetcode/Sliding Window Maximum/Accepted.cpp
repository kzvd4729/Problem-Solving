/****************************************************************************************
*  @author: kzvd4729                                         created: 05/31/2021 01:31                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 252 ms                                          memory_used: 131.9 MB                             
*  problem: https://leetcode.com/problems/sliding-window-maximum
****************************************************************************************/
class Solution {
public:
    vector<int>maxSlidingWindow(vector<int>&a,int k)
{
  deque<int>d;
  vector<int>ret;
  for(int i=0;i<(int)a.size();i++)
  {
    while(d.size() && d.front()<=i-k)d.pop_front();
    while(d.size() && a[d.back()]<=a[i])d.pop_back();
    d.push_back(i);
    if(i+1>=k)ret.push_back(a[d.front()]);
  }
  return ret;
}
};