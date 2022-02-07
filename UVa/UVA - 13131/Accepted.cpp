/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-22 00:42:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 440                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-13131
****************************************************************************************/
#include<stdio.h>
#include<math.h>
int main()
{
    long long int N,a,b,j,i,sum=0,d;
    scanf("%lld",&N);
    for(i=1; i<=N; i++)
    {
        scanf("%lld %lld",&a,&b);
        sum=0;
        if(b==0)
        {
            for(j=1; j<=sqrt(a); j++)
            {
                if(a%j==0)
                {
                    sum=sum+j+a/j;
                }
            }
        }
        else
        {
            for(j=1; j<=sqrt(a); j++)
            {
                if(a%j==0)
                {
                    d=a/j;
                    if(d%b!=0)
                    {
                        sum=sum+d;
                    }
                    if(j%b!=0&&j!=d)
                    {
                        sum=sum+j;
                    }
                }
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}