/****************************************************************************************
*  @author: kzvd4729                                         created: 05/31/2021 01:29                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 292 ms                                          memory_used: 134.1 MB                             
*  problem: https://leetcode.com/problems/sliding-window-maximum
****************************************************************************************/
class Solution {
public:
    vector<int>maxSlidingWindow(vector<int>&a,int k)
{
  deque<pair<int,int> >d;
  vector<int>ret;
  for(int i=0;i<(int)a.size();i++)
  {
    while(d.size() && d.front().second<=i-k)d.pop_front();
    while(d.size() && d.back().first<=a[i])d.pop_back();
    d.push_back({a[i],i});
    if(i+1>=k)ret.push_back(d.front().first);
  }
  return ret;
}
};