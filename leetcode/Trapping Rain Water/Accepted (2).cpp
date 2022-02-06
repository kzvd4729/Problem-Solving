/****************************************************************************************
*  @author: kzvd4729                                         created: 06/02/2021 00:16                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 14.2 MB                              
*  problem: https://leetcode.com/problems/trapping-rain-water
****************************************************************************************/
class Solution {
public:
    int trap(vector<int>&a) 
    {
        int n=a.size();if(n<=2)return 0;
                vector<int>mx(n,0);
        mx[0]=a[0];
                for(int i=1;i<n;i++)mx[i]=max(mx[i-1],a[i]);
                int ans=0,r=a[n-1];
                for(int i=n-2;i>=1;i--)
        {
            int mn=min(mx[i-1],r);
            if(a[i]<mn)ans+=mn-a[i];
                        r=max(r,a[i]);
        }
        return ans;
            }
};