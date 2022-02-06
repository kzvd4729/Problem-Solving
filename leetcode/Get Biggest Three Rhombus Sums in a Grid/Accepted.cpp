/****************************************************************************************
*  @author: kzvd4729                                         created: 05/29/2021 21:04                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 144 ms                                          memory_used: 21.8 MB                              
*  problem: https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid
****************************************************************************************/
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) 
    {
      vector<vector<int> >a=grid;
      int n=a.size(),m=a[0].size();
      vector<int>v;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)v.push_back(a[i][j]);
      }
      for(int sz=2;sz<=100;sz++)
      {
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
            if(j+sz-1+sz-1>=m)continue;
            if(i-sz+1<0)continue;
            if(i+sz-1>=n)continue;
            int sm=a[i][j];
            for(int k=1;k<sz;k++)
            {
              sm+=a[i-k][j+k];
            }
            for(int k=1;k<sz;k++)
            {
              sm+=a[i+k][j+k];
            }
            int ii=i,jj=j+sz-1+sz-1;
            sm+=a[ii][jj];
            for(int k=1;k<sz-1;k++)
            {
              sm+=a[ii-k][jj-k];
            }
            for(int k=1;k<sz-1;k++)
            {
              sm+=a[ii+k][jj-k];
            }
            v.push_back(sm);
          }
        } 
      }
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      reverse(v.begin(),v.end());
      while((int)v.size()>3)v.pop_back();
      return v;
    }
};