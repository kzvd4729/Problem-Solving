/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 15:02                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 8.2 MB                               
*  problem: https://leetcode.com/problems/zigzag-conversion
****************************************************************************************/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};