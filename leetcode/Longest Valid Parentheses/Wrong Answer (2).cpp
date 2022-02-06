/****************************************************************************************
*  @author: kzvd4729                                         created: 05/31/2021 22:28                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/longest-valid-parentheses
****************************************************************************************/
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int ret=0,bl=0;
        for(auto x:s)
        {
            if(x=='(')bl++,ret++;
            else if(bl)bl--,ret++;
        }
        return ret-bl;
    }
};