/****************************************************************************************
*  @author: kzvd4729                                         created: 07/07/2021 15:10                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 116 ms                                          memory_used: 93.4 MB                              
*  problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
****************************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        int ret=0,mn=p[0];
                for(int i=1;i<(int)p.size();i++)
        {
            ret=max(ret,p[i]-mn);
            mn=min(mn,p[i]);
        }
        return ret;
    }
};