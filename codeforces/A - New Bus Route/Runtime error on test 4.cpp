/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2017 21:23                        
*  solution_verdict: Runtime error on test 4                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 72300 KB                             
*  problem: https://codeforces.com/contest/792/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int a[3000000],vis[3000000],nvis[3000000];
int main()
{
    long long int n,i,j,mn,mx,cnt,x,y;
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        memset(nvis,0,sizeof(nvis));
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        mx=9999999999999;
        for(i=0;i<n-1;i++)
        {
            mn=abs(a[i]-a[i+1]);
            if(mn<=mx)mx=mn;
         }
        cnt=0;
        for(i=0;i<n-1;i++)
        {
              mn=abs(a[i]-a[i+1]);
            if(mn==mx)
            {
                if(a[i]>=0&&a[i+1]>=0)
                {
                    if(vis[a[i]]!=1||vis[a[i+1]]!=1)cnt++;
                    vis[a[i]]=1;
                    vis[a[i+1]]=1;
                }
                else if(a[i]<0&&a[i+1]<0)
                {
                    x=a[i]*(-1);
                    y=a[i+1]*(-1);
                    if(nvis[x]!=1||nvis[y]!=1)cnt++;
                    nvis[x]=1;
                    nvis[y]=1;
                 }
                else if(a[i]<0&&a[i+1]>=0)
                {
                    x=a[i]*(-1);
                    y=a[i+1];
                    if(nvis[x]!=1||vis[y]!=1)cnt++;
                    nvis[x]=1;
                    vis[y]=1;
                 }
                else if(a[i]>=0&&a[i+1]<0)
                {
                    x=a[i];
                    y=a[i+1]*(-1);
                    if(vis[x]!=1||nvis[y]!=1)cnt++;
                    vis[x]=1;
                    nvis[y]=1;
                 }
             }
         }
         /*for(i=0;i<=4;i++)
        {
            cout<<vis[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<=4;i++)
        {
            cout<<nvis[i]<<" ";
        }
        cout<<endl;*/
          cout<<mn<<" "<<cnt<<endl;
       }
      return 0;
}