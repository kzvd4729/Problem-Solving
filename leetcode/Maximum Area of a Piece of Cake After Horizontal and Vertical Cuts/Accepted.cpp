/****************************************************************************************
*  @author: kzvd4729                                         created: 06/03/2021 13:27                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 156 ms                                          memory_used: 34.5 MB                              
*  problem: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts
****************************************************************************************/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        vector<int>a=horizontalCuts;
        a.push_back(0);a.push_back(h);
                vector<int>b=verticalCuts;
        b.push_back(0);b.push_back(w);
                sort(a.begin(),a.end());sort(b.begin(),b.end());
                int mx1=0;
        for(int i=1;i<(int)a.size();i++)mx1=max(mx1,a[i]-a[i-1]);
                int mx2=0;
        for(int i=1;i<(int)b.size();i++)mx2=max(mx2,b[i]-b[i-1]);
                return (1LL*mx1*mx2)%1000000007;
    }
};