/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/11/2017 23:00                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/828/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,a,b,i,x,ans,c;
int main()
{
    cin>>n>>a>>b;
    ans=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x==1)
        {
            if(a)a--;
            else
            {
                if(c)c=0;
                else if(b)
                {
                    b--;
                    c=1;
                }
                else ans++;
            }
        }
        if(x==2)
        {
            if(b)b--;
            else ans+=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}