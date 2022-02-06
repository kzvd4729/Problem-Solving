/****************************************************************************************
*  @author: kzvd4729                                         created: 06/17/2021 14:18                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 40 ms                                           memory_used: 38 MB                                
*  problem: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum
****************************************************************************************/
class Solution {
public:
        long long cal(vector<int>a)
    {
        long long ans=0,cnt=0;
        for(int i=0;i<(int)a.size();i++)
        {
            if(a[i]==0)cnt++;
            else
            {
                ans+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        ans+=(cnt*(cnt+1))/2;
        return ans;
    }
        int numSubarrayBoundedMax(vector<int>&a, int l, int r) 
    {
        vector<int>v;
        for(auto x:a)
        {
            if(x>r)v.push_back(1);
            else v.push_back(0);
        }
                long long ans=cal(v);
                v.clear();
        for(auto x:a)
        {
            if(x<l)v.push_back(0);
            else v.push_back(1);
        }
        ans+=-cal(v);
                return (int)ans;
    }
};