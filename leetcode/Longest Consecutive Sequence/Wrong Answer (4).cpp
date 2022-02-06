/****************************************************************************************
*  @author: kzvd4729                                         created: 06/06/2021 20:10                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/longest-consecutive-sequence
****************************************************************************************/
map<int,int>mp,vs;
class Solution {
public:
    int longestConsecutive(vector<int>& a) 
    {
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