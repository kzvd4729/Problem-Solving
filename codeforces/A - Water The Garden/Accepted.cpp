/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2018 20:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/920/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,n,k,arr[202],kk,vis[210];
vector<int>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=k;i++)
        {
            cin>>arr[i];
            vis[arr[i]]=1;
        }
        for(kk=1;  ;kk++)
        {
            int f=0;
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==0)f=1;
            }
            if(f==0)break;
            v.clear();
            for(int i=1;i<=n;i++)
            {
                if(vis[i])v.push_back(i);
            }
            for(auto x:v)
            {
                vis[x-1]=1;
                vis[x+1]=1;
            }
        }
        cout<<kk<<endl;
    }
    return 0;
}