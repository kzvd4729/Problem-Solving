/****************************************************************************************
*  @author: kzvd4729                                         created: 13-04-2017 22:50:10                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.30 sec                                        memory_used: 3.3M                                 
*  problem: https://www.codechef.com/APRIL17/problems/DISHLIFE
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,n,k,vis[100005],v,f,fl,x,flag,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(vis,0,sizeof(vis));
        fl=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            f=0;
            for(j=1;j<=x;j++)
            {
                cin>>v;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    f=1;
                }
            }
            if(f==0)fl=1;
        }
        flag=0;
        for(i=1;i<=k;i++)
        {
            if(vis[k]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)cout<<"sad"<<endl;
        else if(fl==1)cout<<"some"<<endl;
        else cout<<"all"<<endl;
    }
    return 0;
}