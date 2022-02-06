/****************************************************************************************
*  @author: kzvd4729                                         created: 06/02/2021 00:24                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 14.2 MB                              
*  problem: https://leetcode.com/problems/trapping-rain-water
****************************************************************************************/
class Solution {
public:
    int trap(vector<int>&a) 
    {
        int n=a.size();if(n<=2)return 0;
                int mx=-1,id;
        for(int i=0;i<n;i++)if(a[i]>mx)mx=a[i],id=i;
                int cur=a[0],ans=0;
        for(int i=1;i<id;i++)
        {
            if(a[i]<cur)ans+=cur-a[i];
            else cur=a[i];
        }
        cur=a[n-1];
        for(int i=n-2;i>id;i--)
        {
            if(a[i]<cur)ans+=cur-a[i];
            else cur=a[i];
        }
        return ans;
            }
};