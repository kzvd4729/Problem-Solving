/****************************************************************************************
*  @author: kzvd4729                                         created: 07-10-2017 12:46:19                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.06 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/OCT17/problems/MARRAYS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 99999999999
using namespace std;
long t,n,x,z;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        long mn1=inf,mn2=inf,mx1=-inf,mx2=-inf;
        cin>>n;
        cin>>x;
        while(x--)
        {
            cin>>z;
            mn1=min(mn1,z);
            mx1=max(mx1,z);
        }
        cin>>x;
        while(x--)
        {
            cin>>z;
            mn2=min(mn2,z);
            mx2=max(mx2,z);
        }
        cout<<max(abs(mx2-mn1),abs(mx1-mn2))<<endl;
    }
    return 0;
}