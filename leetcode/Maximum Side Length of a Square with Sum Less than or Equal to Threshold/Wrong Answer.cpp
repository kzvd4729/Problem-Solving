/****************************************************************************************
*  @author: kzvd4729                                         created: 12/20/2019 22:52                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
****************************************************************************************/
int sum[300+2][300+2][300+2];
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0; ;k++)
                {
                    if(i-k<0||j-k<0)break;
                    if(k==0)sum[i][j][k]=mat[i][j];
                    else sum[i][j][k]+=mat[i-k][j]+mat[i][j-k];
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sm=0;
                for(int k=0; ;k++)
                {
                    if(i+k>=n||j+k>=m)break;
                    sm+=sum[i+k][j+k][k];
                    if(sm<=threshold)mx=max(mx,k+1);
                }
            }
        }
        return mx;
    }
};