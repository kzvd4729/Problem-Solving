/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-02-07 20:49:25                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-374
****************************************************************************************/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main ()
{
    long int n,modulo,cnt,b,p,m,i;
    while(cin>>b>>p>>m)
    {
        if(p==0)cout<<1<<endl;
        else
        {
            modulo=b;
            for(i=2; i<=p; i++)
            {
                modulo=((modulo%m)*(b%m))%m;
            }
            cout<<modulo<<endl;
        }


    }

    return 0;
}