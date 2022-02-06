/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2017 09:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 655 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/768/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,x,z,fre[1030],tmp[1030],f,mx,mn=9999999999;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k>>x;
    for(long i=1; i<=n; i++)
    {
        cin>>z;
        fre[z]++;
    }
    while(k--)
    {
        for(long j=0; j<=1024; j++)
        {
            tmp[j]=fre[j];
        }
        f=1;
        for(long j=0; j<=1024; j++)
        {
            if(fre[j]<=0)continue;
            long xo=j^x;
            long d=fre[j]/2;
            /*if(fre[j]==1)
            {
                if(f==1)
                {
                    tmp[j]=0;
                    tmp[xo]++;
                    f=0;
                }
                else f=1;
            }*/
            if(fre[j]%2==0)
            {
                tmp[j]-=d;
                tmp[xo]+=d;
            }
            else
            {
                if(f==1)
                {
                    tmp[j]-=d+1;
                    tmp[xo]+=d+1;
                    f=0;
                }
                else
                {
                    tmp[j]-=d;
                    tmp[xo]+=d;
                    f=1;
                }
            }
        }
         for(long j=0; j<=1024; j++)
        {
            fre[j]=tmp[j];
        }
     }
    for(long i=0; i<=1024; i++)
    {
        if(fre[i]>0)
        {
            mx=max(mx,i);
            mn=min(mn,i);
        }
    }
    cout<<mx<<" "<<mn<<endl;
    return 0;
}