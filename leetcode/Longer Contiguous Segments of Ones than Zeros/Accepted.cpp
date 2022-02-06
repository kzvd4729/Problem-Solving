/****************************************************************************************
*  @author: kzvd4729                                         created: 05/29/2021 22:16                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 6.2 MB                               
*  problem: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros
****************************************************************************************/
class Solution {
public:
    bool checkZeroOnes(string s) {
        int one=0,cur=0;
        for(auto x:s)
        {
            if(x=='1')cur++;
            else
            {
                one=max(one,cur);
                cur=0;
            }
        }
        one=max(one,cur);
                int zer=0;cur=0;
        for(auto x:s)
        {
            if(x=='0')cur++;
            else
            {
                zer=max(zer,cur);
                cur=0;
            }
        }
        zer=max(zer,cur);
                return one>zer;
    }
};