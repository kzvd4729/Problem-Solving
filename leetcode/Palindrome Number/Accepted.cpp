/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 15:10                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 5.9 MB                               
*  problem: https://leetcode.com/problems/palindrome-number
****************************************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};