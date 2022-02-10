/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-10 10:41:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 28                                         memory_used (MB): 1.7                             
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
        {
            if(m==1||n==1)
            {
                printf("Case %d: %d\n",++tc,max(m,n));
            }
            else if(m==2||n==2)
            {
                int x=max(m,n);
                int y=min(m,n);
                if(x%4==0)printf("Case %d: %d\n",++tc,max(m,n));
                else if(x%4==2)printf("Case %d: %d\n",++tc,max(m,n)+2);
                else printf("Case %d: %d\n",++tc,max(m,n)+1);
            }
            else printf("Case %d: %d\n",++tc,((m*n)+1)/2);
        }
    }
    
    return 0;
}