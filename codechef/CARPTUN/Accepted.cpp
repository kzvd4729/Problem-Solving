/****************************************************************************************
*  @author: kzvd4729                                         created: 03-02-2018 18:03:11                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.96 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/FEB18/problems/CARPTUN
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n;
double mx,x,c,d,s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            mx=max(mx,x);
        }
        cin>>c>>d>>s;
        cout<<setprecision(12)<<fixed<<mx*(c-1)<<endl;
    }
    return 0;
}