/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2017 09:33                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/883/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s,ss[1003];
long vis[30],vis2[55],n,m;
map<long,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    cin>>s;
    cin>>m;
    long c=0;
    for(long i=0; i<s.size(); i++)
    {
        if(s[i]=='*')
        {
            c++;
            continue;
        }
        vis2[i]=1;
        vis[s[i]-'a']=1;
    }
    for(long i=1; i<=m; i++)
    {
        cin>>ss[i];
        for(long j=0; j<ss[i].size(); j++)
        {
            if(vis[ss[i][j]-'a']==1)ss[i][j]='.';
        }
    }
    long ans=9999999999;
    long cnt;
    for(long j=0; j<n; j++)
    {
        if(vis2[j]==1)continue;
        cnt=0;
        mp.clear();
        for(long i=1; i<=m; i++)
        {
            if(ss[i][j]=='.')continue;
            if(mp[ss[i][j]]==0)cnt++;
            mp[ss[i][j]]=1;
        }
        ans=min(cnt,ans);
     }
    if(ans>c)cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}