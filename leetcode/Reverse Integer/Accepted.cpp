/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 01:02                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 5.8 MB                               
*  problem: https://leetcode.com/problems/reverse-integer
****************************************************************************************/
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};