/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 15:38                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 140 ms                                          memory_used: 59 MB                                
*  problem: https://leetcode.com/problems/container-with-most-water
****************************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& a) {
                int l=0,r=a.size()-1,ans=0;
                while(l<=r)
        {
            ans=max(ans,(r-l)*min(a[l],a[r]));
            if(a[l]<=a[r])l++;
            else r--;
        }
        return ans;
    }
};