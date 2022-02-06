/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2018 16:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 17000 KB                             
*  problem: https://codeforces.com/contest/535/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
int n,m,x,vis[1000006],ok[1000006];
string s;
int kmp[1000006];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
   cin>>n>>m; 
cin>>s;
kmp[0]=0;
for(int i=1;i<s.size();i++)
{
int now=kmp[i-1];
while(true)
{
if(s[i]==s[now])
{
kmp[i]=now+1;
break;               
}
else
{
if(now==0)break;
else now=kmp[now-1];               
}  
}
}
//for(int i=0;i<s.size();i++)cout<<kmp[i]<<" ";
//cout<<endl;
    int l=s.size();
int now=kmp[l-1];
while(true)
{
if(l-now<l)ok[l-now]=1;
if(now==0)break;
now=kmp[now-1];
}
//for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
//cout<<endl;
 for(int i=1;i<=m;i++)cin>>x,vis[x]=1;
 int lt=-1,rt=-1;
long ans=1;
for(int i=1;i<=n;i++)
{
if(vis[i]==1)
{
if(rt<i)lt=i,rt=i+l-1;
else
{
int ds=i-lt;
if(ok[ds]==0)cout<<0<<endl,exit(0);
else lt=i,rt=i+l-1;
}
}
if(i>rt)ans=(ans*26LL)%mod;
}
cout<<ans<<endl;    
return 0;
}