/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-22 23:38:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1083
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,x,tc;
stack<long>pos,hei;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        pos.push(0);
        hei.push(0);
        cin>>n;
        long ans=0;
        for(long i=1;i<=n;i++)
        {
            cin>>x;
            if(x==hei.top())continue;
            if(x>hei.top())
            {
                hei.push(x);
                pos.push(i);
            }
            else
            {
                long top;
                while(hei.top()>=x)
                {
                    top=pos.top();
                    long cal=(i-pos.top())*hei.top();
                    ans=max(ans,cal);
                    pos.pop();
                    hei.pop();
                }
                pos.push(top);
                hei.push(x);
            }
        }
        while(pos.size())
        {
            long cal=(n+1-pos.top())*hei.top();
            ans=max(ans,cal);
            pos.pop();
            hei.pop();
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;

    }
    return 0;
}