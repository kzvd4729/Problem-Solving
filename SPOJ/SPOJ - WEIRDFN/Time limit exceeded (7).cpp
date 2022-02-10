/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-02 00:38:10                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-WEIRDFN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000000007;
long t,a,b,c,n,sum,m,x;
priority_queue<long>pq1,pq2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        while(pq1.size())pq1.pop();
        while(pq2.size())pq2.pop();
        cin>>a>>b>>c>>n;
        sum=1;
        pq1.push(1);
        for(long i=2;i<=n;i++)
        {
            m=pq1.top();
            x=((a*m)%mod+(b*i)%mod+c)%mod;
            sum=(sum+x)%mod;
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
        cout<<sum<<endl;
    }
    return 0;
}