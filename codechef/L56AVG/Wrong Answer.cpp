/****************************************************************************************
*  @author: kzvd4729                                         created: 27-01-2018 22:38:48                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/LTIME56/problems/L56AVG
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,u,v,n;
double arr[100],sum,mn;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        mn=9999999;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            mn=min(mn,arr[i]);
        }
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
        }
        double ans=99999999;
        ans=max(sum/(double)n,mn);
        cout<<setprecision(10)<<fixed<<ans<<endl;
    }
    return 0;
}