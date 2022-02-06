/****************************************************************************************
*  @author: kzvd4729                                         created: 07/23/2021 21:56                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 7.1 MB                               
*  problem: https://leetcode.com/problems/isomorphic-strings
****************************************************************************************/
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        vector<int>mapped(256,-1),taken(256,0);
                for(int i=0;i<(int)s.size();i++)
        {
            int a=s[i],b=t[i];
                        if(mapped[a]==-1)
            {
                if(taken[b])return false;
                else taken[b]=1;
                                mapped[a]=b;
            }
                        if(mapped[a]!=b)return false;
        }
        return true;
    }
};