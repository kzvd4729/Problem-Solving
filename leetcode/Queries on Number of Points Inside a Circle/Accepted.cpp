/****************************************************************************************
*  @author: kzvd4729                                         created: 04/17/2021 20:36                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 1244 ms                                         memory_used: 167.3 MB                             
*  problem: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle
****************************************************************************************/
class Solution 
{
public:
  vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
  {
    vector<int>ans;
    for(auto x:queries)
    {
      ans.push_back(0);
      for(auto p:points)
      {
        int d=(x[0]-p[0])*(x[0]-p[0])+(x[1]-p[1])*(x[1]-p[1]);
        if(d<=x[2]*x[2])ans.back()++;
      }
    }
    return ans;
  }
};