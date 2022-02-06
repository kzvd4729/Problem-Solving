/****************************************************************************************
*  @author: kzvd4729                                         created: 03/09/2021 02:57                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/remove-palindromic-subsequences
****************************************************************************************/
class Solution {
public:
    int removePalindromeSub(string s) {
        string k=s;
        reverse(k.begin(),k.end());
        if(k==s)return 1;
        else return 2;
    }
};