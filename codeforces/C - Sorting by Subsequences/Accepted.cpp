/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2017 01:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/844/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
long arr[N],b[N],vis[N],n;
map<long,long>mp;
vector<long>v[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        b[i]=arr[i];
    }
    sort(b+1,b+n+1);
    for(long i=1; i<=n; i++)
    {
        mp[b[i]]=i;
    }
    long id=0;
    for(long i=1; i<=n; i++)
    {
        if(vis[i]==1)continue;
        ++id;
        long x=i;
        while(true)
        {
            long k=x;
            v[id].push_back(k);
            vis[k]=1;
            x=mp[arr[k]];
            if(vis[x]==1)break;
        }
    }
    cout<<id<<endl;
    for(long i=1;i<=id; i++)
    {
        cout<<v[i].size()<<" ";
        for(long j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
 