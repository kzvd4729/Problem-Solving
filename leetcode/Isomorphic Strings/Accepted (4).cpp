/****************************************************************************************
*  @author: kzvd4729                                         created: 07/12/2021 21:37                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 6.9 MB                               
*  problem: https://leetcode.com/problems/isomorphic-strings
****************************************************************************************/
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        vector<int>lft(256,-1),rgt(256,-1);
                for(int i=0;i<(int)s.size();i++)
        {
            int a=s[i],b=t[i];
                        if(lft[a]==-1 || lft[a]==b);
            else return false;
                        if(rgt[b]==-1 || rgt[b]==a);
            else return false;
                        lft[a]=b;rgt[b]=a;
        }
        return true;
    }
};