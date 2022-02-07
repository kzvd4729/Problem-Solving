/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-08 16:17:18                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10910
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int tc,n,t,p,r,i,j,k;
    while(cin>>tc)
    {
        while(tc--)
        {
            cin>>n>>t>>p;

            r=t-(n*p)+1;
            cout<<(r*(r+1))/2<<endl;

        }

    }

    return 0;
}