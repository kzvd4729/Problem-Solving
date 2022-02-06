/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2017 12:33                        
*  solution_verdict: Time limit exceeded on test 9           language: GNU C++14                               
*  run_time: 10000 ms                                        memory_used: 6600 KB                              
*  problem: https://codeforces.com/contest/802/problem/B
****************************************************************************************/
/*
4 2
1 2 3 1
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,mark[400004],ans,i,arr[400004],j,kk,vis[400004],del,a,f;
int main()
{
    cin>>n>>kk;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<=n;i++)
    {
        if(mark[arr[i]]==0)
        {
            ans++;
            mark[arr[i]]=1;
            kk--;
            if(kk==0)break;
        }
    }
    ///cout<<ans<<endl;
    ///cout<<i<<endl;
    for(j=i+1;j<=n;j++)
    {
        if(mark[arr[j]]==0)
        {
            memset(vis,0,sizeof(vis));
            for(k=j;k<=n;k++)
            {
                if(vis[arr[k]]==0&&mark[arr[k]]==1)
                {
                    del=k;
                    vis[arr[k]]=1;
                }
            }
            for(a=1;a<=400000;a++)
            {
                if(mark[a]==1)
                {
                    f=0;
                    for(k=j;k<=n;k++)
                    {
                        if(a==arr[k])f=1;
                    }
                    if(f==0)
                    {
                        del=a;
                        break;
                    }
                }
            }
            if(f==0)mark[a]=0;
            else mark[arr[del]]=0;
            ans++;
            mark[arr[j]]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}