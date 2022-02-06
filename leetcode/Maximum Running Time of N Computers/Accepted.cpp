/****************************************************************************************
*  @author: kzvd4729                                         created: 01/28/2022 21:05                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 204 ms                                          memory_used: 55.7 MB                              
*  problem: https://leetcode.com/problems/maximum-running-time-of-n-computers
****************************************************************************************/
class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) 
    {
        long long ans=0,lo=1,md,hi=1e15;
        while(lo<=hi)
        {
            md=(lo+hi)/2;
            long long tt=0;
            for(int i=0;i<(int)b.size();i++)
                tt+=min(b[i]*1LL, md);
                        if((tt/n)>=md)
            {
                ans=md;lo=md+1;
            }
            else hi=md-1;
        }
        return ans;
    }
};