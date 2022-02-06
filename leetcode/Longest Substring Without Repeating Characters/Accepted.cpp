/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 00:53                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 32 ms                                           memory_used: 16.2 MB                              
*  problem: https://leetcode.com/problems/longest-substring-without-repeating-characters
****************************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if((int)s.size()==0)return 0;
                int mx=0;
        for(auto c:s)mx=max(mx,(int)c);
                vector<vector<int> >ls(mx+1,vector<int>(2,-1));
                int p=-1,ans=0;
        for(int i=0;i<(int)s.size();i++)
        {
            int c=(int)s[i];
            ls[c][0]=ls[c][1];
            ls[c][1]=i;
                        p=max(p,ls[c][0]);
                        ans=max(ans,i-p);
                    }
        return ans;
            }
};