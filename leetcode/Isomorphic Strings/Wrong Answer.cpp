/****************************************************************************************
*  @author: kzvd4729                                         created: 07/12/2021 21:23                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/isomorphic-strings
****************************************************************************************/
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        vector<int>a(256,0),b(256,0);
                for(auto x:s)a[(int)x]++;
        for(auto x:t)b[(int)x]++;
                sort(a.begin(),a.end());
        sort(b.begin(),b.end());
                return a==b;
            }
};