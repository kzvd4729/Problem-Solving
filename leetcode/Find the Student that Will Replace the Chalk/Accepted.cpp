/****************************************************************************************
*  @author: kzvd4729                                         created: 06/12/2021 20:36                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 132 ms                                          memory_used: 74.3 MB                              
*  problem: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk
****************************************************************************************/
class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
                long long sm=0;
        for(auto x:c)sm+=x;
                k%=sm;
                for(int i=0;i<(int)c.size();i++)
        {
            if(k<c[i])return i;
            k-=c[i];
        }
        return -1;
    }
};