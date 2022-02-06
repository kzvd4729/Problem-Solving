/****************************************************************************************
*  @author: kzvd4729                                         created: 06/20/2021 21:21                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/swim-in-rising-water
****************************************************************************************/
class Solution {
public:
    int swimInWater(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
                for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)continue;
                                int mn=1000000000;
                if(i-1>=0)mn=min(mn,a[i-1][j]);
                if(j-1>=0)mn=min(mn,a[i][j-1]);
                                a[i][j]=max(a[i][j],mn);
            }
        }
                return a[n-1][m-1];
    }
};