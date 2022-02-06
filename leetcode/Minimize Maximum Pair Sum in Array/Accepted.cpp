/****************************************************************************************
*  @author: kzvd4729                                         created: 05/29/2021 20:34                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 220 ms                                          memory_used: 100.5 MB                             
*  problem: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array
****************************************************************************************/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int>a=nums;
                sort(a.begin(),a.end());
                int n=(int)a.size();
        int hf=n/2;
                int mx=0;
        for(int i=0;i<hf;i++)
        {
            mx=max(mx,a[i]+a[n-1-i]);
        }
        return mx;
    }
};