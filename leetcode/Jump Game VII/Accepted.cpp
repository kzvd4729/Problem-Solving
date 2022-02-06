/****************************************************************************************
*  @author: kzvd4729                                         created: 05/29/2021 22:31                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 536 ms                                          memory_used: 67.6 MB                              
*  problem: https://leetcode.com/problems/jump-game-vii
****************************************************************************************/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
                set<int>st;st.insert(0);
                int n=s.size(),ls=1;
        for(int i=1;i<n;i++)
        {
            ls=0;
            if(s[i]=='1')continue;
                        int l=i-maxJump,r=i-minJump;
            auto it=st.lower_bound(l);
            if(it==st.end())continue;
            if(*it<=r)ls=1,st.insert(i);
        }
        return ls;
            }
};