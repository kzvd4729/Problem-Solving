/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-11-01 00:53:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1334
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int kmp[N+2],dp[N+2],pre[N+2],suf[N+2];
void doKmp(string &s)
{
  int n=s.size();kmp[0]=0;
  for(int i=1;i<n;i++)
  {
    int now=kmp[i-1];kmp[i]=0;
    while(true)
    {
      if(s[now]==s[i]){kmp[i]=now+1;break;}
      if(!now)break;now=kmp[now-1];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    string a,b,c;cin>>a>>b;int n=a.size(),m=b.size();
    doKmp(b);
    for(int i=0;i<m;i++)
    {
      dp[i]=1;if(i==m-1)dp[i]=0;
      if(kmp[i])dp[i]+=dp[kmp[i]-1];
    }
    /*for(int i=0;i<m;i++)
      cout<<dp[i]<<" ";
    cout<<endl;*/
    c=b+"#"+a;doKmp(c);
    for(int i=m+1;i<=m+n;i++)
    {
      //cout<<"**"<<kmp[i]<<endl;
      pre[i-m-1]=0;
      if(kmp[i])pre[i-m-1]+=dp[kmp[i]-1];
    }
    /*for(int i=0;i<n;i++)
      cout<<pre[i];
    cout<<endl;*/

    reverse(a.begin(),a.end());reverse(b.begin(),b.end());
    doKmp(b);
    for(int i=0;i<m;i++)
    {
      dp[i]=1;if(i==m-1)dp[i]=0;
      if(kmp[i])dp[i]+=dp[kmp[i]-1];
    }
    c=b+"#"+a;doKmp(c);
    //cout<<c<<endl;
    for(int i=m+1;i<=m+n;i++)
    {
      //cout<<"**"<<kmp[i]<<endl;
      suf[i-m-1]=0;
      if(kmp[i])suf[i-m-1]+=dp[kmp[i]-1];
    }
    /*for(int i=0;i<n;i++)
      cout<<suf[i];
    cout<<endl;*/

    long ans=0;
    for(int i=0;i<n-1;i++)
    {
      //cout<<i<<" --> "<<n-i-2<<" "<<pre[i]<<" "<<suf[n-i-2]<<endl;
      ans+=1LL*pre[i]*suf[n-i-2];
    }
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}