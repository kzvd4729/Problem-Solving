/****************************************************************************************
*  @author: kzvd4729                                         created: 06/06/2021 20:11                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 388 ms                                          memory_used: 41.3 MB                              
*  problem: https://leetcode.com/problems/longest-consecutive-sequence
****************************************************************************************/
class Solution {
public:
    int longestConsecutive(vector<int>& a) 
    {
      map<int,int>mp,vs;
      if((int)a.size()==0)return 0;
      for(auto x:a)mp[x]=1;
      int mx=0;
      for(auto x:a)
      {
        if(vs.count(x))continue;
        vs[x]=1;int cnt=1;
        for(int i=x+1; ;i++)
        {
          if(mp.count(i))cnt++,vs[i]=1;
          else break;
        }
        for(int i=x-1; ;i--)
        {
          if(mp.count(i))cnt++,vs[i]=1;
          else break;
        }
        mx=max(mx,cnt);
      }
      return mx;
    }
};