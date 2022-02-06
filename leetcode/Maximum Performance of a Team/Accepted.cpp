/****************************************************************************************
*  @author: kzvd4729                                         created: 06/05/2021 15:05                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 116 ms                                          memory_used: 36.7 MB                              
*  problem: https://leetcode.com/problems/maximum-performance-of-a-team
****************************************************************************************/
const int mod=1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) 
    {
        vector<pair<int,int> >v;
        for(int i=0;i<n;i++)v.push_back({ef[i],sp[i]});
                sort(v.begin(),v.end());
                priority_queue<int>st;long long ans=0,sm=0;
        for(int i=n-1;i>=0;i--)
        {
            st.push(-v[i].second);
            sm+=v[i].second;
                        if((int)st.size()>k)
            {
                sm+=st.top();st.pop();
            }
                        ans=max(ans,1LL*v[i].first*sm);
        }
        return ans%mod;
    }
};