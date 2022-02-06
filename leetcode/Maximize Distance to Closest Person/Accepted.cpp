/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 00:29                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 12 ms                                           memory_used: 18.3 MB                              
*  problem: https://leetcode.com/problems/maximize-distance-to-closest-person
****************************************************************************************/
class Solution {
public:
        const int inf=1e6;
    int maxDistToClosest(vector<int>& a) 
    {
        vector<int>lft;
                int pt=-inf;
                for(int i=0;i<a.size();i++)
        {
            if(a[i]==1)pt=i;
                        lft.push_back(i-pt);
        }
                pt=inf;int ans=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i]==1)pt=i;
                        ans=max(ans,min(lft[i],pt-i));
        }
        return ans;
            }
};