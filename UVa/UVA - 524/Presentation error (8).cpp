/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-03 00:58:54                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-524
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,pn[30],vis[30];
int p[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0};
void fx(int t)
{
    int i;
    if(t==n&&p[pn[n-1]+1]==1)
    {
        for(int j=0;j<n;j++)
        {
            cout<<pn[j]<<" ";
        }
        cout<<endl;
        return ;
    }
    for(i=2;i<=n;i++)
    {
        if(vis[i]==0)
        {
            if(p[i+pn[t-1]])
            {
                pn[t]=i;
                vis[i]=1;
                fx(t+1);
                vis[i]=0;
            }
        }
    }
}
int main()
{
    int tc=0;
    while(cin>>n)
    {
        if(tc)cout<<endl;
        cout<<"Case "<<++tc<<":"<<endl;
        memset(vis,0,sizeof(vis));
        pn[0]=1;
        fx(1);

    }
    return 0;
}