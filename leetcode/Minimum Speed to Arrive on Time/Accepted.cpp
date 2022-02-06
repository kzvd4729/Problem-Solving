/****************************************************************************************
*  @author: kzvd4729                                         created: 05/29/2021 22:24                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 768 ms                                          memory_used: 101.5 MB                             
*  problem: https://leetcode.com/problems/minimum-speed-to-arrive-on-time
****************************************************************************************/
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int lo=1,hi=1000000000;int ans=-1;
        while(lo<=hi)
        {
            int md=(lo+hi)/2;double req=0;
            for(int i=0;i<(int)dist.size()-1;i++)
            {
                req+=(int)((dist[i]+md-1)/md);
            }
            req+=(dist.back()*1.0)/(md*1.0);
            if(req<=hour)
            {
                ans=md;hi=md-1;
            }
            else lo=md+1;
        }
        return ans;
    }
};