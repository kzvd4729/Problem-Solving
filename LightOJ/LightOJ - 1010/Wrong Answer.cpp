/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-08 19:07:11                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1010
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m,n,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        if(m==1||n==1)
        {
            printf("Case %d: %d\n",++tc,max(m,n));
        }
        else if(m==2&&n==2)
        {
            printf("Case %d: %d\n",++tc,4);
        }
        else if(m==2||n==2)
        {
            if(m%2==0&&n%2==0)
            {
                printf("Case %d: %d\n",++tc,((m*n)+1)/2)+2;
            }
            else printf("Case %d: %d\n",++tc,((m*n)+1)/2)+1;
        }
        else printf("Case %d: %d\n",++tc,((m*n)+1)/2);
    }
    return 0;
}