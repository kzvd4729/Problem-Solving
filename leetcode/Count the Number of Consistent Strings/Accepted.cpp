/****************************************************************************************
*  @author: kzvd4729                                         created: 06/08/2021 23:02                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 60 ms                                           memory_used: 30.2 MB                              
*  problem: https://leetcode.com/problems/count-the-number-of-consistent-strings
****************************************************************************************/
class Solution {
public:
    int countConsistentStrings(string a, vector<string>& w) 
    {
        vector<int>v(26,0);
        for(auto x:a)v[x-'a']=1;
                int cnt=0;
        for(auto x:w)
        {
            int f=1;
            for(auto z:x)f&=v[z-'a'];
            cnt+=f;
        }
        return cnt;
    }
};