/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-10 21:07:25                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10050
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,c,p,arr[109],vis[4000],cnt,i,j;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>c;
        cin>>p;
        for(i=0;i<p;i++)
        {
            cin>>arr[i];
        }
        for(i=6;i<=c;i+=7)
        {
            vis[i]=1;
        }
        for(i=7;i<=c;i+=7)
        {
            vis[i]=1;
        }

        cnt=0;
        for(i=0;i<p;i++)
        {
            for(j=arr[i];j<=c;j+=arr[i])
            {
                if(vis[j]==0)cnt++;
                vis[j]=1;
            }
        }
        cout<<cnt<<endl;


    }
    return 0;
}