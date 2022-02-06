/****************************************************************************************
*  @author: kzvd4729                                         created: 06/12/2021 20:32                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 9.1 MB                               
*  problem: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered
****************************************************************************************/
class Solution {
public:
    bool isCovered(vector<vector<int>>& a, int l, int r) 
    {
        vector<int>vs(100+2,0);
                for(auto x:a)
        {
            for(int i=x[0];i<=x[1];i++)vs[i]=1;
        }
        int f=1;
        for(int i=l;i<=r;i++)f&=vs[i];
                return f;
    }
};