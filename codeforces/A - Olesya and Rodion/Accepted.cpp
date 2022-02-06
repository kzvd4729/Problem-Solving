/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/22/2017 15:06                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/584/problem/A
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    int n,t,z,i;
    char num[101],x;
    while(cin>>n>>t)
    {
        num[0]='1';
        for(i=1; i<n; i++)
        {
            num[i]='0';
        }
        if(t==10)
        {
            if(n==1)cout<<-1<<endl;
            else
            {
                for(i=0; i<n; i++)
                {
                    cout<<num[i];
                }
                cout<<endl;
            }
         }
        else
        {
            z=0;
            for(i=0; i<n; i++)
            {
                z=(z*10+num[i]-'0')%t;
            }
            z=t-z;
            for(i=0; i<n; i++)
            {
                if(i==n-1)num[i]=num[i]+z;
                cout<<num[i];
            }
             cout<<endl;
        }
     }
     return 0;
}