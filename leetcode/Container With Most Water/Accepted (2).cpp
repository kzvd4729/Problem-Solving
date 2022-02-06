/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 15:40                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 88 ms                                           memory_used: 59.1 MB                              
*  problem: https://leetcode.com/problems/container-with-most-water
****************************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& a) {
                int l=0,r=a.size()-1,ans=0;
                while(l<=r)
        {
            if(a[l]<=a[r])ans=max(ans,(r-l)*a[l++]);
            else ans=max(ans,(r-l)*a[r--]);
        }
        return ans;
    }
};