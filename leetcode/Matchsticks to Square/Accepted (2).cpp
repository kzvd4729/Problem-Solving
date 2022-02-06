/****************************************************************************************
*  @author: kzvd4729                                         created: 06/15/2021 20:11                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 320 ms                                          memory_used: 17.1 MB                              
*  problem: https://leetcode.com/problems/matchsticks-to-square
****************************************************************************************/
class Solution {
public:
    bool makesquare(vector<int>& a) 
    {
        long long tt=0;
        for(int i=(int)a.size()-1;i>=0;i--)
        {
            tt+=a[i];
            if(a[i]==0)a.erase(a.begin()+i);
        }
        if(tt%4)return false;tt/=4;
        //cout<<tt<<endl;
        int n=a.size();if(n==0)assert(0);
                vector<int>dp((1<<n),0);
                dp[0]=1;
        for(int i=1;i<(1<<n);i++)
        {
            long long sm=0;
            for(int j=0;j<n;j++)if(i&(1<<j))sm+=a[j];
                        for(int j=0;j<n;j++)
            {
                if((i&(1<<j))==0)continue;
                if(sm/tt==(sm-a[j])/tt)dp[i]|=dp[i^(1<<j)];
                if((sm%tt==0) && (sm/tt==((sm-a[j])/tt)+1))dp[i]|=dp[i^(1<<j)];
            }
        }
        //for(int i=0;i<(1<<n);i++)cout<<dp[i]<<" ";cout<<endl;
        return dp[(1<<n)-1];
    }
};