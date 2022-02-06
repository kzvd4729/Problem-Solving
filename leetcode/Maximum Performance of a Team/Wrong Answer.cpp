/****************************************************************************************
*  @author: kzvd4729                                         created: 06/05/2021 14:56                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
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
                multiset<int>st;int sm=0;long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            st.insert(v[i].second);
            sm=(sm+v[i].second)%mod;
                        if((int)st.size()>k)
            {
                int b=*st.begin();st.erase(st.find(b));
                sm=(sm-b+mod)%mod;
            }
                        ans=max(ans,1LL*v[i].first*sm);
        }
        return ans%mod;
    }
};