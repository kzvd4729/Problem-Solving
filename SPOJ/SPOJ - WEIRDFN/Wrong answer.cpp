/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-02 02:10:36                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-WEIRDFN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int mod=1000000007;
int t,a,b,c,n,sum,m,x;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        priority_queue<int>pq1,pq2;
        scanf("%d%d%d%d",&a,&b,&c,&n);
        sum=1;
        pq1.push(1);
        for(int i=2;i<=n;i++)
        {
            m=pq1.top();
            x=((long)((long)(a*m)+(long)(b*i)+c))%mod;
            sum+=x;
            pq1.push(x);
            x=pq1.top();
            pq1.pop();
            pq2.push(-x);
            if(pq2.size()>pq1.size())
            {
                x=-pq2.top();
                pq2.pop();
                pq1.push(x);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}