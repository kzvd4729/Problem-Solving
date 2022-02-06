/****************************************************************************************
*  @author: kzvd4729                                         created: 06/11/2021 15:12                         
*  solution_verdict: Time Limit Exceeded                     language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/stone-game-vii
****************************************************************************************/
class Solution 
{
public:
    int dfs(vector<int>&a,int i,int j)
    {
        if(i>j)return 0;
                int ret=a[j]-a[i]-dfs(a,i+1,j);
                int cs=0;
        if(j)cs+=a[j-1];
        if(i)cs-=a[i-1];
                ret=max(ret,cs-dfs(a,i,j-1));
                return ret;
    }
    int stoneGameVII(vector<int>& a) 
    {
        vector<int>b=a;
        for(int i=1;i<(int)b.size();i++)b[i]+=b[i-1];
        return dfs(b,0,b.size()-1);
    }
};