/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2017 09:30:18                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.05 sec                                        memory_used: 3.1M                                 
*  problem: https://www.codechef.com/JULY17/problems/CALC
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,b,cnt,x,i,ans,ns;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>b;
        ans=0;
        for(i=1;i<=n;i++)
        {
            x=n-i;
            ns=i*(x/b);
            ans=max(ans,ns);
        }
        cout<<ans<<endl;
    }
    return 0;
}