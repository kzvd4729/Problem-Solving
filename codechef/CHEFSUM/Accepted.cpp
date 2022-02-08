/****************************************************************************************
*  @author: kzvd4729                                         created: 05-09-2017 22:09:28                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.05 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/SEPT17/problems/CHEFSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,ans,mn,x,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        mn=INT_MAX;
        for(long i=1;i<=n;i++)
        {
            cin>>x;
            if(x<mn)
            {
                mn=x;
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
2
3
1 2 3
4
2 1 3 1
*/