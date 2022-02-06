/****************************************************************************************
*  @author: kzvd4729                                         created: 05/29/2021 20:31                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 20 ms                                           memory_used: 8.1 MB                               
*  problem: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters
****************************************************************************************/
class Solution {
public:
    int countGoodSubstrings(string s) {
                int cnt=0;
        for(int i=2;i<(int)s.size();i++)
        {
            set<char>st;
            for(int j=i-2;j<=i;j++)st.insert(s[j]);
                        if((int)st.size()==3)cnt++;
                    }
        return cnt;
            }
};