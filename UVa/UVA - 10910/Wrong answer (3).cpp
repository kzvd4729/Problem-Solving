/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-08 16:00:42                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10910
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,n,t,p,r,i,j,k,cnt;
    while(cin>>tc)
    {
        while(tc--)
        {
            cnt=0;
            cin>>n>>t>>p;
            r=t-(2*p);
            for(i=p;i<=r;i++)
            {
                for(j=p;j<=r;j++)
                {
                    for(k=p;k<=r;k++)
                    {
                        if(i+j+k==t)cnt++;
                    }
                }
            }

            cout<<cnt<<endl;

        }



    }


    return 0;
}