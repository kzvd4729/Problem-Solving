/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-28 00:31:26                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 224                                        memory_used (MB): 3.3                             
*  problem: https://vjudge.net/problem/LightOJ-1112
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
using namespace std;
long t,n,q,bit[100005],arr[100005],tc,x1,x2,x3;
void updp(long id,long v)
{
    for( ; id<=n; id+=id&-id)
    {
        bit[id]+=v;
    }
}
void updm(long id,long v)
{
    for( ; id<=n; id+=id&-id)
    {
        bit[id]-=v;
    }
}
long get(long id)
{
    long sum=0;
    for( ;id>0;id-=id&-id)
    {
        sum+=bit[id];
    }
    return sum;
}
int main()
{
    scanf("%lld",&t);
    tc=0;
    while(t--)
    {
        memset(bit,0,sizeof(bit));
        scanf("%lld%lld",&n,&q);
        for(long i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
            updp(i,arr[i]);
        }
        printf("Case %lld:\n",++tc);
        while(q--)
        {
            scanf("%lld",&x1);
            if(x1==1)
            {
                scanf("%lld",&x2);
                x2++;
                printf("%lld\n",arr[x2]);
                updm(x2,arr[x2]);
                arr[x2]=0;
            }
            else if(x1==2)
            {
                scanf("%lld%lld",&x2,&x3);
                x2++;
                arr[x2]+=x3;
                updp(x2,x3);
            }
            else
            {
                scanf("%lld%lld",&x2,&x3);
                x2++;
                x3++;
                printf("%lld\n",get(x3)-get(x2-1));
            }

        }

    }

    return 0;
}