/****************************************************************************************
*  @author: kzvd4729                                         created: 03/09/2021 02:58                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 6.1 MB                               
*  problem: https://leetcode.com/problems/remove-palindromic-subsequences
****************************************************************************************/
class Solution {
public:
    int removePalindromeSub(string s) {
        if((int)s.size()==0)return 0;
        string k=s;
        reverse(k.begin(),k.end());
        if(k==s)return 1;
        else return 2;
    }
};