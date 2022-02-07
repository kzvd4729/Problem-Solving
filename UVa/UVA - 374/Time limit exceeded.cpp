/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-11 19:51:45                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-374
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    long long int b,p,m,i,ans;
    while(cin>>b>>p>>m)
    {
        ans=b;
        for(i=2;i<=p;i++)
        {
            ans=(ans*b)%m;
        }
        cout<<ans<<endl;


    }

    return 0;
}