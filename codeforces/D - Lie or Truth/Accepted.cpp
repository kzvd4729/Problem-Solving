/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2017 23:06                        
*  solution_verdict: Accepted                                language: GNU C11                                 
*  run_time: 62 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/795/problem/D
****************************************************************************************/
#include<stdio.h>
int main()
{
    long long int n,l,r,arr[100005],brr[100005],i,f;
    scanf("%lld%lld%lld",&n,&l,&r);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&brr[i]);
    }
    f=0;
    for(i=1;i<l;i++)
    {
        if(arr[i]!=brr[i])
        {
            f=1;
            break;
        }
    }
    for(i=r+1;i<=n;i++)
    {
        if(arr[i]!=brr[i])
        {
            f=1;
            break;
        }
    }
    if(f==1)printf("LIE\n");
    else printf("TRUTH\n");
    return 0;
}