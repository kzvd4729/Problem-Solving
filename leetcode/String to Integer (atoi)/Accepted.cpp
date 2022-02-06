/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 15:08                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 7 MB                                 
*  problem: https://leetcode.com/problems/string-to-integer-atoi
****************************************************************************************/
class Solution {
public:
   int myAtoi(string str) {
    if (str.empty()) return 0;
    int i = 0, sign = 1;
    while (i + 1 < str.size() && isspace(str[i])) ++i;
    long res = 0;
    if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
    while (i < str.size()) {
        if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
        else return res * sign;
        if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
    }
    return res * sign;
}
};