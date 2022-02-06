/****************************************************************************************
*  @author: kzvd4729                                         created: 07/19/2021 01:22                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 6.6 MB                               
*  problem: https://leetcode.com/problems/pascals-triangle
****************************************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int> >v(n);
        v[0]={1};
                for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int sm=0;
                if(j<(int)v[i-2].size())sm+=v[i-2][j];
                if(j-1>=0)sm+=v[i-2][j-1];
                                v[i-1].push_back(sm);
                            }
        }
        return v;
    }
};