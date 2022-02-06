/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2017 00:37                        
*  solution_verdict: Wrong answer on pretest 6               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 5800 KB                              
*  problem: https://codeforces.com/contest/844/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
long a[N],b[N],vis[N],n,id;
map<long,long>srt,mp;
vector<long>v[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>a[i];
        mp[a[i]]=i;
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(long i=1; i<=n; i++)
    {
        srt[b[i]]=i;
    }
    id=0;
    for(long i=1; i<=n; i++)
    {
        if(vis[i]==1)continue;
        long sp=srt[a[i]];
        if(srt[a[sp]]==i)
        {
            if(a[i]==a[sp])v[++id].push_back(i);
            else
            {
                v[++id].push_back(i);
                v[id].push_back(sp);
            }
            vis[i]=1;
            vis[sp]=1;
            //cout<<i<<" "<<srt[a[i]]<<endl;
        }
    }
    for(long i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            v[0].push_back(i);
        }
    }
    if(v[0].size())
    {
        cout<<id+1<<endl;
        for(long i=0; i<=id; i++)
        {
            if(v[i].size()==0)continue;
            cout<<v[i].size()<<" ";
            for(long j=0; j<v[i].size(); j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
     }
    else
    {
        cout<<id<<endl;
        for(long i=1; i<=id; i++)
        {
            if(v[i].size()==0)continue;
            cout<<v[i].size()<<" ";
            for(long j=0; j<v[i].size(); j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
     }
     return 0;
}