/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-21 19:19:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10871
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],lim,n,arr[N+2],qm[N+2],x,f,t,ans,id;
void seive(void)
{
  vis[1]=1;
  lim=sqrt(N)+1;
  for(int i=4;i<=N;i+=2)vis[i]=1;
  for(int i=3;i<=N;i+=2)
  {
    if(vis[i])continue;
    if(i>lim)continue;
    for(int j=i*i;j<=N;j+=2*i)vis[j]=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  seive();
  cin>>t;
  while(t--)
  {
    cin>>n;
    qm[0]=0;
    for(int i=1;i<=n;i++)cin>>arr[i],qm[i]=qm[i-1]+arr[i];
    f=0;
    for(int j=2;j<=n;j++)
    {
      for(int i=1;i<=n;i++)
      {
        if(i+j-1>n)break;
        x=qm[i+j-1]-qm[i-1];
        if(x>N)continue;
        if(vis[x]==0)
        {
          f=1;
          ans=j;
          id=i;
          break;
        }
      }
      if(f)break;
    }
    if(f)
    {
      cout<<"Shortest primed subsequence is length "<<ans<<": ";
      for(int i=id;i<id+ans;i++)
      {
        if(i!=id)cout<<" ";
        cout<<arr[i];
      }
      cout<<endl;
    }
    else cout<<"This sequence is anti-primed."<<endl;
  }
  return 0;
}